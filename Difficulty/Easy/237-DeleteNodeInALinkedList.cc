/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 拷贝整个结点，将要删除的结点的下一个结点整个拷贝到待删除结点
// 这样待删除的结点就是它本身的下一个结点，包括next域也是下一个结点的next域
// 这样原本的下一个结点就没有人指向，可以删除

// 都不用删除结点空间
class Solution
{
  public:
    void deleteNode(ListNode *node)
    {
        *node = *node->next;
    }
};

// 释放结点空间
class Solution
{
  public:
    void deleteNode(ListNode *node)
    {
        ListNode *nodeToDel = node->next;
        *node = *node->next;
        delete nodeToDel;
        nodeToDel = nullptr;
    }
};
