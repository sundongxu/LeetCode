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
    还是可以递归呀
 */
class Solution
{
  public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if (!t1 || !t2) // 结束条件
            return t1 ? t1 : t2;

        // 新建树，空间复杂度增减
        // TreeNode *node = new TreeNode(t1->val + t2->val); // 两树都非空的话相加元素值
        // node->left = mergeTrees(t1->left, t2->left);
        // node->right = mergeTrees(t1->right, t2->right);
        // return node;

        // 直接用t1
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};

/* 
    迭代也试试
 */
class Solution
{
  public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if (!t1 || !t2) // 结束条件
            return t1 ? t1 : t2;

        stack<pair<TreeNode *, TreeNode *>> s;
        s.push(make_pair(t1, t2));

        while (!s.empty())
        {
            auto node1 = s.top().first;
            auto node2 = s.top().second;
            s.pop();

            if (node1 == nullptr || node2 == nullptr)
                continue;
            // 两者都不为空了
            node1->val += node2->val;
            if (node1->left == null)
                node1->left = node2->left;
            else
                s.push(make_pair(node1->left, node2->left));

            if (node1->right == nullptr)
                node1->right = node2->right;
            else
                s.push(make_pair(node1->right, node2->right));
        }

        return t1;
    }
};
