/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 即二叉树镜像问题，递归
class Solution
{
  public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        TreeNode *right = invertTree(root->right);
        TreeNode *left = invertTree(root->left);
        root->left = right;
        root->right = left;

        return root;
    }
};

// 迭代
class Solution
{
  public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            TreeNode *temp = cur->left;
            cur->left = cur->right;
            cur->right = temp;
            if (cur->left != nullptr)
                q.push(cur->left);
            if (cur->right != nullptr)
                q.push(cur->right);
        }
        return root;
    }
};