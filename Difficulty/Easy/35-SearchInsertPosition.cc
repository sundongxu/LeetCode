// My Version
class Solution
{
  public:
    int searchInsert(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < target)
                continue;
            else
                return i;
        }
        return nums.size();
    }
};

// 二分查找！！！
class Solution
{
  public:
    int searchInsert(vector<int> &nums, int target)
    {
        return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
    }

    template <typename ForwardIterator, typename T>
    ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, T value)
    {
        while (first != last)
        {
            auto mid = next(first, distance(first, last) / 2);
            if (value > *mid)
                first = ++mid;
            else
                last = mid;
        }
        return first;
    }
};