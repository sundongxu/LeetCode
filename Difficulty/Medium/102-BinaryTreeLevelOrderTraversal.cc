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
            swap(next, cur); // cur与next互换元素，cur又非空啦
        }
        return result;
    }
};

// discuss简洁版

class Solution
{
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;
        deque<TreeNode *> tree; // 双端队列
        tree.push_back(root);
        int flag = 0;
        while (!tree.empty())
        {
            int count = tree.size();
            vector<int> level;
            while (count-- > 0)
            {
                TreeNode *cur = tree.front();
                tree.pop_front();
                level.push_back(cur->val);
                if (cur->left)
                    tree.push_back(cur->left);
                if (cur->right)
                    tree.push_back(cur->right);
            }
            if (flag & 1) // 得到最后1 bit的值
                reverse(level.begin(), level.end());
            result.push_back(level);
            flag++;
        }
        return result;
    }
};