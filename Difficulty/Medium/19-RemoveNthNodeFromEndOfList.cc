/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* 
    题目要求：删除链表的倒数第n个结点
    时间复杂度O(n)，空间复杂度O(1)
 */
class Solution
{
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy, *q = &dummy;
        for (int i = 0; i < n; i++) // 让q先走n步，但是记得从dummy出发的
            q = q->next;

        while (q->next) // q未到末尾即持续循环
        {
            p = p->next;
            q = q->next;
        }
        // 循环结束，q指向倒数第1个结点，p指向倒数第n+1个结点
        // 删除倒数第n个结点，实际就是当前p的下一个结点
        ListNode *tmp = p->next;
        p->next = p->next->next;
        delete tmp;
        return dummy.next;
    }
};