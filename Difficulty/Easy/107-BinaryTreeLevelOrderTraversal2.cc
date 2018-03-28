/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* 
    没啥好说的...直接把102的结果reverse一样就好了
 */
class Solution
{
  public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result;
        traverse(root, 1, result);
        reverse(result.begin(), result.end());
        return result;
    }
    // level对应root所在层，根结点为第一层
    void traverse(TreeNode *root, size_t level, vector<vector<int>> &result)
    {
        if (!root) // 结束条件
            return;
        if (level > result.size())
            result.push_back(vector<int>());
        result[level - 1].push_back(root->val);
        traverse(root->left, level + 1, result);
        traverse(root->right, level + 1, result);
    }
};