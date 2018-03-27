/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        // 边界条件判断
        if (root == nullptr)
            return false;

        if (root->left == nullptr && root->right == nullptr) // 只有唯一结点
            return root->val == sum;

        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};