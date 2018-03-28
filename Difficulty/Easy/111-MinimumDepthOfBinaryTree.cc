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
    递归版本，结束条件一定要写对
 */
class Solution
{
  public:
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left || !root->right)
            return !root->left ? minDepth(root->right) + 1 : minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

/* 
    看看人家的递归呢？
    这个hasBrother标志位，我只能说我服...
 */
class Solution
{
  public:
    int minDepth(const TreeNode *root)
    {
        return minDepth(root, false);
    }

  private:
    int minDepth(const TreeNode *root, bool hasbrother)
    {
        if (!root)
            return hasbrother ? INT_MAX : 0;
        return 1 + min(minDepth(root->left, root->right != NULL),
                       minDepth(root->right, root->left != NULL));
    }
};

/* 
    迭代版
 */
class Solution
{
  public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int result = INT_MAX;
        stack<pair<TreeNode *, int>> s;
        s.push(make_pair(root, 1));
        while (!s.empty())
        {
            auto node = s.top().first;
            auto depth = s.top().second;
            s.pop();
            if (node->left == nullptr && node->right == nullptr)
                result = min(result, depth);
            if (node->left && result > depth) // 深度控制，剪枝
                s.push(make_pair(node->left, depth + 1));
            if (node->right && result > depth)
                s.push(make_pair(node->right, depth + 1));
        }
        return result;
    }
};