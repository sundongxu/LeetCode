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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }

    template <class InputIterator>
    TreeNode *buildTree(InputIterator in_first, InputIterator in_last, InputIterator post_first, InputIterator post_last)
    {
        if (in_first == in_last)
            return nullptr;
        if (post_first == post_last)
            return nullptr;

        auto val = *prev(post_last);
        TreeNode *root = new TreeNode(val);

        auto inRootPos = find(in_first, in_last, val);
        auto leftSize = distance(in_first, inRootPos);
        auto post_left_last = next(post_first, leftSize);

        root->left = buildTree(in_first, inRootPos, post_first, post_left_last);
        root->right = buildTree(next(inRootPos), in_last, post_left_last, prev(post_last));
    }
};