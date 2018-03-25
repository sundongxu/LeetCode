class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums.size(); // 因为最多可允许两个重复，那size小于2的数组直接就是结果

        int index = 2;
        for (int i = 2; i < nums.size(); ++i)
            if (nums[i] != nums[index - 2])
                nums[index++] = nums[i];
        return index;
    }
};

// 另一个版本，效率高得多
class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        const int n = nums.size();
        int index = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i > 0 && i < n - 1 && nums[i] == nums[i - 1] && nums[i] == nums[i + 1])
                continue; // 如果有连续三个或以上的，跳过中间所有重复元素
            // 只有第一个和最后一个会被放入新数组
            nums[index++] = nums[i];
        }
        return index;
    }
};