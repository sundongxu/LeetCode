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
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return;

        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        slow = reverse(slow);

        // merge two lists
        ListNode *cur = head;
        while (cur->next)
        {
            ListNode *tmp = cur->next;
            cur->next = slow;
            slow = slow->next;
            cur->next->next = tmp;
            cur = tmp;
        }
        cur->next = slow;
    }

    // 反转单链表
    ListNode *reverse(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *prev = head;
        for (ListNode *cur = head->next, *next = cur->next; cur; prev = cur, cur = next, next = next ? next->next : nullptr)
            cur->next = prev;

        head->next = nullptr;
        return prev;  // 现在成为了反转链表的头节点，实际是原链表的尾结点
    }
};