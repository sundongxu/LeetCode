/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

// 常规操作，没有释放结点空间
class Solution
{
  public:
    ListNode *removeElements(ListNode *head, int val)
    {
        struct ListNode *cur = head;
        struct ListNode *prev = nullptr;

        if (head == nullptr)
            return nullptr;

        while (cur)
        {
            if (cur->val == val)
            {
                if (prev)
                {
                    // 要删除current
                    ListNode *tmp = cur;
                    prev->next = cur->next;
                    // tmp->next = nullptr;
                    delete tmp;
                    tmp = nullptr;
                }
                else
                {
                    ListNode *tmp = head;
                    head = head->next; // 删除头结点
                    // tmp->next = nullptr;
                    delete tmp;
                    tmp = nullptr;
                }
            }
            else
            {
                prev = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};

// 巧妙操作
class Solution
{
  public:
    ListNode *removeElements(ListNode *&head, int val)
    {
        auto **ptr = &head;
        while (*ptr)
        {
            if ((*ptr)->val == val)
            {
                *ptr = (*ptr)->next;
            }
            else
            {
                ptr = &(*ptr)->next;
            }
        }
        return head;
    }
};