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
    递归版1
 */
class Solution
{
  public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr) // 终止条件
            return;
        flatten(root->left);
        flatten(root->right);

        if (root->left == nullptr)
            return;
        // 三方合并，将左子树所形成的链表插入到root和root->right之间
        TreeNode *node = root->left;
        while (node->right)
            node = node->right;
        node->right = root->right;
        root->right = root->left;
        root->left = nullptr;
    }
};

/* 
    递归版2
 */
class Solution
{
  public:
    void flatten(TreeNode *root)
    {
        flatten(root, nullptr);
    }

  private:
    // 把root所代表的树变成链表后，tail跟在该链表后面
    TreeNode *flatten(TreeNode *root, TreeNode *tail)
    {
        if (root == nullptr) // 结束条件
            return tail;
        root->right = flatten(root->left, flatten(root->right, tail));
        root->left = nullptr;
        return root;
    }
};

/* 
    迭代版
 */
class Solution
{
  public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            auto node = s.top();
            s.pop();
            if (node->right)
                s.push(node->right);
            if (node->left)
                s.push(node->left);
            node->left = nullptr;
            if (!s.empty())
                node->right = s.top();
        }
    }
};