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
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return vector<TreeNoe *>();
        return generate(1, n);
    }

  private:
    vector<TreeNode *> generate(int start, int end)
    {
        vector<TreeNode *> subTree;
        if (start > end)
        {
            subTree.push_back(nullptr);
            return subTree;
        }

        for (int k = start; k <= end; k++)
        {
            vector<TreeNode *> leftSubTree = generate(start, k - 1);
            vector<TreeNode *> rightSubTree = generate(k + 1, end);
            for (auto i : leftSubTree)
            {
                for (auto j : rightSubTree)
                {
                    TreeNode *node = new TreeNode(k);
                    node->left = i;
                    node->right = j;
                    subTree.push_back(node);
                }
            }
        }

        return subTree;
    }
};