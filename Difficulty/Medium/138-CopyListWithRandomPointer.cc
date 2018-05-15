/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution
{
  public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        // 在原结点下一个位置接上该结点拷贝
        for (RandomListNode *cur = head; cur != nullptr;)
        {
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }

        // 为拷贝结点构造random指针
        // 注意到：原结点random指向的结点的拷贝结点，即在其该结点random指向的结点的下一位置
        // 令原结点的拷贝结点指向该拷贝的random指向结点
        for (RandomListNode *cur = head; cur != nullptr;)
        {
            if (cur->random != nullptr)
                cur->next->random = cur->random->next;
            cur = cur->next->next; // cur跳过自己的拷贝结点(cur的下一位置)
        }

        // 分拆两个链表
        RandomListNode dummy(-1);
        for (RandomListNode *cur = head, *new_cur = &dummy; cur != nullptr;)
        {
            new_cur->next = cur->next;
            new_cur = new_cur->next; // 后移新链表
            cur->next = cur->next->next;
            cur = cur->next; // 后移原链表
        }

        return dummy.next;
    }
};