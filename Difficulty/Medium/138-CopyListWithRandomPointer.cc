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

        // 构造每个节点的拷贝，分别插入到原节点之后，此时链表含两倍节点
        for (RandomListNode *cur = head; cur != nullptr;)
        {
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }

        // 为拷贝节点构造random指针
        // 注意到：原节点random指向的节点的拷贝节点，即在其该节点random指向的节点的下一位置
        // 令原节点的拷贝节点的random指针指向其random指向节点的拷贝节点
        for (RandomListNode *cur = head; cur != nullptr;)
        {
            if (cur->random != nullptr)
                cur->next->random = cur->random->next;
            cur = cur->next->next; // cur跳过自己的拷贝节点(cur的下一位置)
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