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
    递归版，so easy
 */
class Solution
{
  public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        postorderHelp(root, result);
        return result;
    }

  private:
    void postorderHelp(TreeNode *root, vector<int> &nodes)
    {
        if (root == nullptr)
            return;
        postorderHelp(root->left, nodes);
        postorderHelp(root->right, nodes);
        nodes.push_back(root->val);
    }
};

/* 
    非递归版，有点难，还是用到栈，不过元素是一个pair，first是结点指针，second是方向
 */
class Solution
{
  public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (root == nullptr)
            return result;

        stack<pair<TreeNode *, char>> s;
        TreeNode *p = root;

        do
        {
            while (p != nullptr)
            {
                s.push(make_pair(p, 'L'));
                p = p->left;
            }
            bool shouldContinue = true;
            while (shouldContinue && !s.empty())
            {
                auto pair_top = s.top();
                s.pop();
                p = pair_top.first;
                switch (pair_top.second)
                {
                case 'L':
                    pair_top.second = 'R';
                    s.push(pair_top);
                    shouldContinue = false;
                    p = p->right;
                    break;
                case 'R':
                    result.push_back(pair_top.first->val);
                    break;
                }
            }
        } while (!s.empty());

        return result;
    }
};
