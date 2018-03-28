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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        // ListNode *p = head; // 记录重复元素值
        // while (p && p->next)  // 可以只判断p->next是否为空
        // {
        //     if (p->val == p->next->val)
        //     {
        //         ListNode *pp = p->next;
        //         p->next = pp->next;
        //         delete pp;
        //         pp = nullptr;
        //     }
        //     else
        //         p = p->next;
        // }
        for (ListNode *prev = head, *cur = head->next; cur; cur = prev->next)
        {
            if (prev->val == cur->val)
            {
                prev->next = cur->next;
                delete cur;
            }
            else
                prev = cur;
        }
        return head;
    }
};