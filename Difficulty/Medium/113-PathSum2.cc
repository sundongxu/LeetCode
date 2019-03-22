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
    vector<vector<int>> dfs(TreeNode *root, int sum)
    {
        vector<vector<int>> result;
        vector<int> path; // 当前路径
        dfs(root, sum, path, result);
        return result;
    }

  private:
    void dfs(TreeNode *root, int gap, vector<int> &path, vector<vector<int>> &result)
    {
        if (root == nullptr)
            return;

        path.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr)  // 已经是叶子，路径到底了
            if (gap == root->val)
                result.push_back(path);

        dfs(root->left, gap - root->val, path, result);
        dfs(root->right, gap - root->val, path, result);
        path.pop_back();
    }
};