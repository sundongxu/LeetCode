// 二分查找
class Solution
{
  public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size() - 1;
        int low = 1;  // 数字下限
        int high = n; // 数字上限
        int mid;
        while (low < high)
        {
            mid = (low + high) / 2;
            int count = 0;
            for (int num : nums)
            {
                if (num <= mid)
                    count++;
            }
            // 数组中 小于等于 大小排在中间的元素值mid 的元素个数比mid还要大(如果不重复的话，就是1~mid，共计mid个)
            // 那么重复数字一定比mid小，搜索上限值设为mid，因为mid也可能重复
            if (count > mid)
                high = mid;
            else // count <= mid，搜索下限值
                low = mid + 1;
        }
        return low;
    }
};