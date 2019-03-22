// 计数排序...好吧居然beat了100%...
// 没啥好说的...但其实也是O(n)的时间复杂度和O(1)的空间复杂度
class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        int counts[3] = {0}; // 记录每个颜色出现的次数
        for (int i = 0; i < nums.size(); i++)
            counts[nums[i]]++;
        for (int i = 0, index = 0; i < 3; i++)
            for (int j = 0; j < counts[i]; j++)
                nums[index++] = i; // index为当前插入的位置
    }
};

// 双指针夹逼法
// 由于只有三个颜色，可以设置两个index作指针，一个是red的index，一个是blue的index
// 两边往中间走，时间复杂度O(n)，空间复杂度O(1)
class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        int red = 0, blue = nums.size() - 1;
        for (int i = 0; i < blue + 1;) // i碰到blue就结束
        {
            if (nums[i] == 0)
                swap(nums[i++], nums[red++]);
            else if (nums[i] == 2)
                swap(nums[i], nums[blue--]);
            else
                i++;
        }
    }
};

// 利用快速排序里Partition的思想
// 第一次将数组按0分割，第二次将数组按1分割
// 排序完毕，可以推广到n种颜色，每种颜色有重复元素的情况
class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        partition(partition(nums.begin(), nums.end(), bind1st(equal_to<int>(), 0)),
                  nums.end(), bind1st(equal_to<int>(), 1));
    }
};

// 重新实现partition()
class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        partition(partition(nums.begin(), nums.end(), bind1st(equal_to<int>(), 0)),
                  nums.end(), bind1st(equal_to<int>(), 1));
    }

  private:
    template <typename ForwardIterator, typename UnaryPredicate>
    ForwardIterator partition(ForwardIterator first, ForwardIterator last,
                              UnaryPredicate pred)
    {
        auto pos = first;
        for (; first != last; ++first)
            if (pred(*first))
                swap(*first, *pos++);
        return pos;
    }
};