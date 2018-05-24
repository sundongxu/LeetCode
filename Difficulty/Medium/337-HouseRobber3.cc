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
    // root为根结点，l为抢劫此树的左孩子得到的金额，r为抢劫此树的右孩子得到的金额
    int tryRob(TreeNode *root, int &l, int &r)
    {
        if (root == nullptr)
            return 0;
        // ll、lr、rl、rr分别代表抢劫root的孙子结点(左孩子的左孩子、左孩子的右孩子、右孩子的左孩子、右孩子的右孩子)得到的金额
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = tryRob(root->left, ll, lr);
        r = tryRob(root->right, rl, rr);

        // 最后在两种情形下取最大值：
        // ① 抢根结点root，再抢其四个孙子
        // ② 不抢根结点root，只抢其两个孩子
        return max(root->val + ll + lr + rl + rr, l + r);
    }

    int rob(TreeNode *root)
    {
        int l, r;
        return tryRob(root, l, r);
    }
};