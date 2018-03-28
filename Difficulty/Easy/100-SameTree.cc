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
    先来个递归版的
    注意递归的结束条件
 */
class Solution
{
  public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // 递归深度优先
        // 结束条件
        // if (p == nullptr && q == nullptr) // 两个都为空
        //     return true;
        // if (p == nullptr || q == nullptr) // 一个为空一个不为空
        //     return false;
        // 上面直接合并为一句
        if (!p || !q)
            return p == q;
        // 两个都不为空了
        // 两个树相等的条件为：根节点元素值相等，且左右子树均相同
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

/* 
    有递归就能写非递归的，那就迭代咯
    妙，实在是妙
    不过迭代在想返回true的时候要特别慎重，一般是在循环之外即程序最后返回true
 */
class Solution
{
  public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // 不用递归.用迭代
        stack<TreeNode *> s;
        s.push(p);
        s.push(q);

        while (!s.empty())
        {
            // 每次取连续的两个，即两棵树的对应结点
            p = s.top();
            s.pop();
            q = s.top();
            s.pop();
            if (!p && !q) // 两个都为空，当然相同，但是可能后面的结点还没遍历到，还不能简单就返回了
                continue;
            if (!q || !p) // 仅一个为空，当然不同
                return false;
            if (p->val != q->val) // 都不空时，比较元素值
                return false;     // 元素值不一样，当然不一样
            // 将两棵树的对应结点相邻入栈
            s.push(p->left);
            s.push(q->left);
            s.push(p->right);
            s.push(q->right);
        }
        // 能比较到这里的，都是人才，两树当然相同啦
        return true;
    }
};