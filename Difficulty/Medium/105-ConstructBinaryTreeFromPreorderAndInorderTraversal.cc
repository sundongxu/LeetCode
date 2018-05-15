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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }

    template <class InputIterator>
    TreeNode *buildTree(InputIterator pre_first, InputIterator pre_last, InputIterator in_first, InputIterator in_last)
    {
        if (pre_first == pre_last)
            return nullptr;
        if (in_first == in_last)
            return nullptr;

        auto root = new TreeNode(*pre_first); // 根结点即前序遍历序列第一个结点

        auto inRootPos = find(in_first, in_last, *pre_first); // 在中序遍历序列中找到根结点位置，其左边即根结点左子树，右边即根结点右子树
        auto leftSize = distance(in_first, inRootPos);

        root->left = buildTree(next(pre_first), next(pre_first, leftSize + 1), in_first, next(in_first, leftSize)); // 两对范围都是左闭右开
        root->right = buildTree(next(pre_first, leftSize + 1), pre_last, next(inRootPos), in_last);

        return root;
    }
};