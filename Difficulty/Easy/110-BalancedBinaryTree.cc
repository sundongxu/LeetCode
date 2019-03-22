/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    bool isBalanced(TreeNode *root)
    {
        return balanceHeight(root) >= 0;
    }

    // 如果root为一个平衡树，则返回其高度
    // 否则，返回-1
    int balanceHeight(TreeNode *root)
    {
        if (root == nullptr) // 终止条件
            return 0;
        int left = balanceHeight(root->left);
        int right = balanceHeight(root->right);

        // （1）left < 0即左子树不是平衡树 
        // （2）right < 0即右子树不是平衡树 
        // （3）两者高度差绝对值大于1
        // 都可以说明以root为根结点的树不是平衡树
        if (left < 0 || right < 0 || abs(left - right) > 1)
            return -1;
        // 以root为根结点的树的高度为其左右结点高度的较大值+1(root增加一个高度)
        return max(left, right) + 1; // 三方合并，以root为根的树是平衡树，返回其高度
    }
};