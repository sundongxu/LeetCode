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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // 边界条件检查，有指针就要判空
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode head(-1);
        ListNode *p = &head; // p指向head结点，但之后p后移，而head结点仍旧是头结点
        // 注意这个头结点不是l1或者l2中的任何元素，返回的时候应该是从head.next开始返回
        for (; l1 != nullptr && l2 != nullptr; p = p->next)
            if (l1->val > l2->val)
            {
                p->next = l2;
                l2 = l2->next;
            }
            else
            {
                p->next = l1;
                l1 = l1->next;
            }
        p->next = l1 != nullptr ? l1 : l2; // 把元素没用完的list接在最后
        return head.next;                  // 返回p? 返回&head?
    }
};