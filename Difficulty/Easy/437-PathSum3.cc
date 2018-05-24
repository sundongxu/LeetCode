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
    // 跳过某些结点
    int pathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return 0;
        // 统计包含根结点在内的路径，以及不包含根结点而分别包含根结点的左孩子和右孩子在内的两种路径
        return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

  private:
    // 计算 在之前和为pre的基础上，再加上当前结点的值 的和
    int sumUp(TreeNode *root, int pre, int &sum)
    {
        if (root == nullptr)
            return 0;
        int current = pre + root->val;
        return (current == sum) + sumUp(root->left, current, sum) + sumUp(root->right, current, sum);
    }
};