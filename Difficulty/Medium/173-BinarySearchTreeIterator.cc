/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator
{
  public:
    BSTIterator(TreeNode *root)
    {
        push(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *node = s.top();
        s.pop();
        push(node->right);
        return node->val;
    }

    void push(TreeNode *node)
    {
        while (node != nullptr)
        {
            s.push(node);
            node = node->left;
        }
    }

  private:
    stack<TreeNode *> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */