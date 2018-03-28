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
    照例还是先递归
 */
class Solution
{
  public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        inOrderHelp(root, result);
        return result;
    }

  private:
    // 传一个vector引用就解决了每次都要往同一个result里面追加新元素的问题
    void inOrderHelp(TreeNode *root, vector<int> &nodes)
    {
        if (root == nullptr) // 结束条件
            return;
        inOrderHelp(root->left, nodes);
        nodes.push_back(root->val);
        inOrderHelp(root->right, nodes);
    }
};

/*
    迭代当然也能行，用一个栈记录
 */
class Solution
{
  public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (root == nullptr)
            return result;

        stack<TreeNode *> s;
        TreeNode *p = root;

        do
        {
            while (p != nullptr)
            {
                // 先找到最左边的结点，沿途结点都入栈
                s.push(p);
                p = p->left;
            }

            if (!s.empty())
            {
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            }

        } while (p != nullptr || !s.empty()); // 结束条件是遍历指针为空且栈为空

        return result;
    }
};