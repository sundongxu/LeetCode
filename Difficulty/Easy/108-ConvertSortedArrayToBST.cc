struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    TreeNode *sortedArrayToBST(vector<int> &num)
    {
        if (num.size() == 0)
            return NULL;
        if (num.size() == 1)
        {
            return new TreeNode(num[0]);
        }

        // 选择中间位置结点(即按数值顺序也是排在中间的)作为当前构造的BST的root结点
        int middle = num.size() / 2;
        TreeNode *root = new TreeNode(num[middle]);

        // 平均分成两拨，数量相差最多1
        vector<int> leftInts(num.begin(), num.begin() + middle);
        // 不包含middle哦，middle已经被用作root结点了
        vector<int> rightInts(num.begin() + middle + 1, num.end());
        // 辅助空间消耗O(n)

        root->left = sortedArrayToBST(leftInts);
        root->right = sortedArrayToBST(rightInts);

        return root;
    }
};

class Solution
{
  public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return help(nums, 0, nums.size() - 1);
    }

    TreeNode *help(vector<int> &nums, int start, int end)
    {
        int _size = end - start;
        if (_size < 0)
            return NULL;
        if (_size == 0)
            return new TreeNode(nums[start]);
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = help(nums, start, mid - 1);
        root->right = help(nums, mid + 1, end);
    }
};