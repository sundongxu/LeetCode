/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        ListNode dummy(-1);
        dummy.next = head;

        ListNode *prev = &dummy;
        for (int i = 0; i < m - 1; i++)
            prev = prev->next;
        ListNode *head2 = prev;
        prev = head2->next;         // prev此时指向第m个结点
        ListNode *cur = prev->next; // cur此时指向第m+1个结点
        for (int i = m; i < n; i++)
        {
            prev->next = cur->next;
            cur->next = head2->next;
            head2->next = cur; // 头插法，将cur结点直接插入到第m个位置
            cur = prev->next;
        }
        return dummy.next;
    }
};