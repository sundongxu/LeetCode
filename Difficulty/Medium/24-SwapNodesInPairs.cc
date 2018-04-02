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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode dummy(-1); // 套路，总是创建一个无意义的头结点，位于给定的head结点之前
        dummy.next = head;

        for (ListNode *prev = &dummy, *cur = prev->next, *next = cur->next; // 当前结点、当前结点的前驱与后继
             next;
             prev = cur, cur = cur->next, next = cur ? cur->next : nullptr)
        {
            // for的第三个表达式很关键，对next迭代赋值时当然先要考虑cur是否为空，如果为空，那next也为空，直接结束循环
            // prev、cur、next依次后移两个位置

            // 下面代码完成cur与next的位置互换
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
        }
        return dummy.next;
    }
};