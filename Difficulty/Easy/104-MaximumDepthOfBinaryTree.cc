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
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        // root非空，树深度当然先+1
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;  // 左右子树中选最深的作为基准继续下去
    }
};