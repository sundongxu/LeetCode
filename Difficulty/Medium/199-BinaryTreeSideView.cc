/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// BFS，即层次遍历，每次只把最右边结点保存到结果
class Solution
{
  public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;

        queue<TreeNode *> q;
        TreeNode *curr;
        int levelNodeCnt;
        q.push(root);

        while (!q.empty())
        {
            levelNodeCnt = q.size();
            while (--levelNodeCnt >= 0)
            {
                curr = q.front();
                q.pop();
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            res.push_back(curr->val); //now curr point to the rightest node of the level
        }
        return res;
    }
};

// DFS，根右左顺序遍历，前序遍历(根左右)的变种
class Solution
{
  public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        helper(result, root, 0); // 根结点是第0层
        return result;
    }

    void helper(vector<int> &result, TreeNode *node, int level)
    {
        if (node == nullptr)
            return;

        // 当前结点从右边可见，因为当前层数从0开始算，而result从1开始算
        // 而两者应该相等，因为每一层都要有一个从右边可见的结点
        // 那么两者相等时，说明result中此时还应添加一个元素
        if (result.size() == level)
            result.emplace_back(node->val);

        helper(result, node->right, level + 1);
        helper(result, node->left, level + 1);
    }
};
