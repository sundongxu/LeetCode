/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution
// {
//   public:
//     bool isSubtree(TreeNode *s, TreeNode *t)
//     {
//         return isSubtree(s, t, false);
//     }

//     bool isSubtree(TreeNode *s, TreeNode *t, bool pre)
//     {
//         if (s == nullptr && t == nullptr) // 子树t匹配完成
//             return pre ? true : false;
//         if (s == nullptr ||  t == nullptr)
//             return false;
//         if (s->val == t->val)
//             return isSubtree(s->left, t->left, true) && isSubtree(s->right, t->right, true);
//         return isSubtree(s->left, t, false) || isSubtree(s->right, t, false);
//     }
// };

class Solution
{
  public:
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (s == nullptr)
            return false;
        if (isSame(s, t))
            return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

  private:
    bool isSame(TreeNode *a, TreeNode *b)
    {
        if (a == nullptr && b == nullptr)
            return true;
        if ((a == nullptr || b == nullptr) || a->val != b->val)
            return false;

        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }
};