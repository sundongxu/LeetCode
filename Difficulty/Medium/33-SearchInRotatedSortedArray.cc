/* 
    数组不含重复元素，且局部都是升序的，想到二分查找，难度在于左右边界的确定
    mid = first + (last - first) / 2
    目标元素值等于mid元素值，直接返回mid
    目标元素值若大于mid元素值，则first = mid + 1，即下一步搜索范围为[mid+1, last)
    目标元素值若小于mid元素值，则last = mid，即下一步搜索范围为[first, mid)
    那么分如下两种情况讨论：
    （1）当nums[first] <= nums[mid]，则说明从first到mid是升序排列的，对此段可以应用二分查找
    （2）当nums[first] > nums[mid]，则说明从mid到last-1是升序排列的，对此段可以应用二分查找
    last通常指向某区间最后一个元素之后的位置，实际没有元素，即区间是[first, last)，左闭右开的
 */

// 二分查找，时间复杂度O(logn)，空间复杂度O(1)
class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        int first = 0, last = nums.size();
        while (first != last)
        {
            int mid = (first + last) / 2; // 二分查找关键
            if (nums[mid] == target)
                return mid;
            if (nums[first] <= nums[mid]) // 说明从first到mid是升序排列的
            {
                if (nums[first] <= target && target < nums[mid])
                    last = mid;
                else
                    first = mid + 1;
            }
            else // first > mid，则从mid到last-1是升序排列的
            {
                if (nums[mid] < target && target <= nums[last - 1])
                    first = mid + 1;
                else
                    last = mid;
            }
        }
        return -1;
    }
};