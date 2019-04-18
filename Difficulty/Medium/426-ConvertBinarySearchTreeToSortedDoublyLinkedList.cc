/**
 * Definition for a binary tree node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    Node *treeToDoublyList(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        // head是最左节点，pre是上一个遍历到的节点
        Node *head = nullptr, *pre = nullptr;
        treeToDoublyList(root, pre, head);
        pre->right = head;
        head->left = pre;
        return head;
    }
    void treeToDoublyList(Node *node, Node *&pre, Node *&head)
    {
        if (node == nullptr)
            return;
        treeToDoublyList(node->left, pre, head); // 对左子树递归
        if (head == nullptr)
        {
            head = node;
            pre = node;
        }
        else
        {
            pre->right = node;
            node->left = pre;
            pre = node;
        }
        treeToDoublyList(node->right, pre, head); // 对右子树递归
    }

    // 解法二：
    void treeToDoublyList(Node *root, Node *&prev, Node *&head)
    {
        if (root == nullptr)
            return;
        treeToDoublyList(root->left, prev, head);
        // 当前结点p的left指向前一个结点prev
        root->left = prev;
        if (prev != nullptr)
            prev->right = root; // 前一个结点的right指向当前结点
        else
            head = root; // 如果前面没有结点，则设置head为当前结点（当前结点为最小的结点）。
        // 递归结束后，head的left指针指向最后一个结点
        // 最后一个结点的右指针指向head结点。注意保存p的right指针，因为在后面代码中会修改该指针。
        head->left = root;
        root->right = head;
        prev = root; //更新前一个结点
        treeToDoublyList(root->right, prev, head);
    }

    // 主函数，初始化prev和head为NULL
    Node *treeToDoublyList(Node *root)
    {
        Node *prev = nullptr;
        Node *head = nullptr;
        treeToDoublyList(root, prev, head);
        return head;
    }
};