struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* 
    My False Version
    Are you kidding me?
    没考虑左右对称啊，只考虑单个左子树和右子树各自自身对不对称干啥！！！
    真正的对称树，是全局对称的！
*/
class Solution
{
  public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        if (!root->left && !root->right)
            return true;
        if (!root->left || !root->right)
            return false;
        return root->left->val == root->right->val && isSymmetric(root->left) && isSymmetric(root->right);
    }
};

/* 
    正确的递归姿势
    再重载一个判断函数，参数变为两个，左右子树是否全局对称
*/
class Solution
{
  public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *p, TreeNode *q)
    {
        if (!p && !q) // 左右子树全为空，当然对称
            return true;
        if (!p || !q) // 左右子树仅有一个为空，当然不对称
            return false;
        // 下面这个参数传递很巧妙啦：
        // 左子树的左子树和右子树的右子树对不对称
        // 左子树的右子树和右子树的左子树对不对称
        return p->val == q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }
};

/* 
    非递归怎么写呢？
    当然还是迭代
    迭代在想返回true的时候要特别慎重，一般是在循环之外即程序最后返回true
 */
class Solution
{
  public:
    // bool isSymmetric(TreeNode *root)
    // {
    //     if (!root)
    //         return true;
    //     return isSymmetric(root->left, root->right);
    // }

    // bool isSymmetric(TreeNode *p, TreeNode *q)
    // {
    //     if (!p && !q) // 左右子树全为空，当然对称
    //         return true;
    //     if (!p || !q) // 左右子树仅有一个为空，当然不对称
    //         return false;
    //     // 下面这个参数传递很巧妙啦：
    //     // 左子树的左子树和右子树的右子树对不对称
    //     // 左子树的右子树和右子树的左子树对不对称
    //     return p->val == q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    // }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        stack<TreeNode *> s;
        s.push(root->left);
        s.push(root->right);

        TreeNode *p = nullptr, *q = nullptr;
        while (!s.empty())
        {
            p = s.top();
            s.pop();
            q = s.top();
            s.pop();
            if (!p && !q) // 左右子树全为空，当然对称，但是到这里还没遍历完后面的结点
                continue;
            if (!p || !q) // 左右子树仅有一个为空，当然不对称
                return false;
            if (p->val != q->val)
                return false;
            // 将p、q对称位置相邻入栈
            s.push(p->left);
            s.push(q->right);
            s.push(p->right);
            s.push(q->left);
        }
        // 呐，我说了，活到现在的都是人才，一定对称
        return true;
    }
};
