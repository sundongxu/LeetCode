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
        struct ListNode *current = head;
        struct ListNode *prev = nullptr;

        if (head == nullptr)
            return nullptr;

        while (current)
        {
            if (current->val == val)
            {
                if (prev)
                {
                    // 要删除current
                    ListNode *nodeToDel = current;
                    prev->next = current->next;
                    // nodeToDel->next = nullptr;
                    delete nodeToDel;
                    nodeToDel = nullptr;
                }
                else
                {
                    ListNode *nodeToDel = head;
                    head = head->next; // 删除头结点
                    // nodeToDel->next = nullptr;
                    delete nodeToDel;
                    nodeToDel = nullptr;
                }
            }
            else
            {
                prev = current;
            }
            current = current->next;
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