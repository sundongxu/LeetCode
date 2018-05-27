/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

// DFS
class Solution
{
  public:
    int maxdiadepth = 0; // 记录递归遍历过程中的最大路径长度

    int dfs(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int leftdepth = dfs(root->left);
        int rightdepth = dfs(root->right);

        if (leftdepth + rightdepth > maxdiadepth) // 以当前结点为根结点的某个路径的总长度大于之前记录的最大长度
            maxdiadepth = leftdepth + rightdepth;
        return max(leftdepth + 1, rightdepth + 1);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return maxdiadepth;
    }
};

class Solution
{
  public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int res = depth(root->left) + depth(root->right);
        return max(res, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }

    int depth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
};