/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 递归版
class Solution
{
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        traverse(root, 1, result, true); // root所在第一层，起始从左往右
        return result;
    }

  private:
    void traverse(TreeNode *root, size_t level, vector<vector<int>> &result, bool left_to_right)
    {
        if (!root) // 终止条件
            return;
        if (level > result.size())
            result.push_back(vector<int>());
        if (left_to_right)
            result[level - 1].push_back(root->val);
        else                                                                // right_to_left，从右往左
            result[level - 1].insert(result[level - 1].begin(), root->val); // 翻转，将当前元素插入到本层遍历结果最前面
        traverse(root->left, level + 1, result, !left_to_right);
        traverse(root->right, level + 1, result, !left_to_right);
    }
};

// 迭代版
class Solution
{
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        queue<TreeNode *> cur, next;
        bool left_to_right = true;

        if (root == nullptr)
            return result;
        else
            cur.push(root);

        while (!cur.empty())
        {
            vector<int> level;
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
            if (!left_to_right)
                reverse(level.begin(), level.end());
            result.push_back(level);
            left_to_right = !left_to_right;
            swap(next, cur);
        }
        return result;
    }
};