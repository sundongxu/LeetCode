/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
/* 
    树不一定是完美二叉树，而可为任意树
    递归，时间复杂度O(n)，空间复杂度O(1)
 */
class Solution
{
  public:
    void connect(TreeLinkNode *root)
    {
        if (root == nullptr)
            return;
        TreeLinkNode dummy(-1);
        for (TreeLinkNode *cur = root, *prev = &dummy; cur; cur = cur->next)
        {
            if (cur->left != nullptr)
            {
                prev->next = cur->left;
                prev = prev->next;
            }
            if (cur->right != nullptr)
            {
                prev->next = cur->right;
                prev = prev->next;
            }
        }
        connect(dummy.next);
    }
};

/* 
    迭代，时间复杂度O(n)，空间复杂度O(1)
 */
class Solution
{
  public:
    void connect(TreeLinkNode *root)
    {
        while (root)
        {
            TreeLinkNode *next = nullptr; // the first node of next level
            TreeLinkNode *prev = nullptr; // previous node on the same level
            for (; root; root = root->next)
            {
                if (!next)
                    next = root->left ? root->left : root->right;
                if (root->left)
                {
                    if (prev)
                        prev->next = root->left;
                    prev = root->left;
                }
                if (root->right)
                {
                    if (prev)
                        prev->next = root->right;
                    prev = root->right;
                }
            }
            root = next; // turn to next level
        }
    }
};