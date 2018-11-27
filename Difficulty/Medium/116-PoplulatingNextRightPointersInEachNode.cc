/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
/* 
    题目要求：
    将树结点的next指针指向其下一个右结点，即右兄弟，若无右兄弟则指针置为nullptr
    并假定给定的是完美二叉树/满二叉树，即叶子结点都在同一层上，并且每个父亲结点的子结点个数相同都为2个

    注意到，每层最右边结点的next域总是NULL，其余的结点的next域总是指向其该层中从左到右的下一个结点
 */
// 时间复杂度O(n)，空间复杂度O(logn)
class Solution
{
  public:
    void connect(TreeLinkNode *root)
    {
        connect(root, nullptr); // root的右兄弟为空
    }

  private:
    void connect(TreeLinkNode *root, TreeLinkNode *sibling)
    {
        if (root == nullptr)
            return;
        else
            root->next = sibling;

        connect(root->left, root->right);

        if (sibling != nullptr)
            connect(root->right, sibling->left);
        else
            connect(root->right, nullptr);
    }
};