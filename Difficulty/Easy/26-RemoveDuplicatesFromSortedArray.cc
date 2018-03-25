// 涨知识的sync_with_stdio! 提升效率惊人！
static int x = []() {
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false); // 禁用cin和cout的缓冲机制
    // untie cin & cout
    cin.tie(NULL); // 解除cin与cout的绑定
    return 0;
}();

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int offset = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[offset] != nums[i])
            {
                nums[++offset] = nums[i];
            }
        }

        return nums.size() == 0 ? 0 : offset + 1;
    }
};

// 我的...
class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        // 条件反射，有容器必先判空
        if (nums.empty())
            return 0;

        // nums是升序排列的有序数组
        int index = 0; // index代表新元素下标
        for (int i = 1; i < nums.size(); ++i)
            if (nums[index] != nums[i])
                nums[++index] = nums[i]; // 找到一个不一样的元素就插入到index的后一个位置
        return index + 1;                // 最后一个下标+1即数组长度
    }
};

// 巧妙一点的，效率会高点儿
// 我的天哪...什么代码加上这个都无敌了...
static int x = []() {
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}();

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int count = 0; // 重复元素计数器
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                count++;
            }
            else
            {
                // i-count实际就是当前要填入的新数组的下标，有count个重复元素
                nums[i - count] = nums[i];
            }
        }

        return nums.size() - count;
    }
};

// STL版本
// 使用STL中的 advance和 distance 方法来进行iterator的加减
static int x = []() {
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}();

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        // unique会帮你重排nums中的元素，都是inplace的
        // 不重复的会移动到最前面，返回一个指向最后一个不重复元素的下一个位置的迭代器
        return distance(nums.begin(), unique(nums.begin(), nums.end()));
    }
};

// STL的另一个版本
// 不管三七二十一，上来就加一段这个
static int x = []() {
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}();

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        return distance(nums.begin(), removeDuplicates(nums.begin(), nums.end(), nums.begin()));
    }

    template <typename InIt, typename OutIt>
    OutIt removeDuplicates(InIt first, InIt last, OutIt output)
    {
        while (first != last)
        {
            *output++ = *first;
            first = upper_bound(first, last, *first);
        }
        return output;
    }
};