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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        preorderHelp(root, result);
        return result;
    }

  private:
    void preorderHelp(TreeNode *root, vector<int> &nodes)
    {
        if (root == nullptr)
            return;
        nodes.push_back(root->val);
        preorderHelp(root->left, nodes);
        preorderHelp(root->right, nodes);
    }
};

/* 
    迭代版，用一个栈来记录
    每次访问完一个结点，就将其右子女入栈，遍历指针指向左子女
 */
class Solution
{
  public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (root == nullptr)
            return result;
        stack<TreeNode *> s;
        TreeNode *p = root;
        s.push(root);

        while (!s.empty())
        {
            p = s.top();
            s.pop();
            result.push_back(p->val);
            if (p->right != nullptr)
                s.push(p->right);
            if (p->left != nullptr)
                s.push(p->left);
        }
        return result;
    }
};
