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
    照例先来递归版
 */
class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        traverse(root, 1, result);
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

/* 
    然后再来迭代
 */
class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        queue<TreeNode *> cur, next; // 注意哦，用的队列
        if (!root)
            return result;
        else
            cur.push(root);
        while (!cur.empty())
        {
            vector<int> level; // 存储当前level的结点
            while (!cur.empty())
            {
                TreeNode *node = cur.front();
                cur.pop();
                level.push_back(node->val);
                if (node->left != nullptr)
                    next.push(node->left);
                if (node->right != nullptr)
                    next.push(node->right);
            }
            result.push_back(level);
            swap(next, cur);
        }
        return result;
    }
};