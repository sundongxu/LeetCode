/* 
    数组依旧是局部升序的，但是可能包含重复元素
    33题的思想是：如果A[m] >= A[l]，那么[l,m]为递增序列
    但是本题中由于可包含重复元素就不一定成立了，如 [1,3,1,1,1]
    如果A[m] >= A[l]，A[2] = 1 >= A[0] = 1，但是[0,2]并非递增序列
    那就想到把 A[m] >= A[l] 分为两种情况：
    （1）如A[m] > A[l]，那么[l,m]一定递增
    （2）如A[m] == A[l]，则确定不了，那么将l++，缩小范围，直至能确定递增关系为止
 */

// 修改后的二分查找，时间复杂度O(n)，空间复杂度O(1)
class Solution
{
  public:
    bool search(vector<int> &nums, int target)
    {
        int first = 0, last = nums.size();
        while (first != last)
        {
            int mid = (first + last) / 2; // 二分查找关键
            if (nums[mid] == target)
                return true;
            if (nums[first] < nums[mid]) // 说明从first到mid是升序排列的
            {
                if (nums[first] <= target && target < nums[mid])
                    last = mid;
                else
                    first = mid + 1;
            }
            else if (nums[first] == nums[mid])
            {
                first++;
            }
            else // first > mid，则从mid到last-1是升序排列的
            {
                if (nums[mid] < target && target <= nums[last - 1])
                    first = mid + 1;
                else
                    last = mid;
            }
        }
        return false;
    }
};