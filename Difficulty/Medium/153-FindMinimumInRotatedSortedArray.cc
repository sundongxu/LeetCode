class Solution
{
  public:
    int findMin(vector<int> &nums)
    {
        int first = 0, last = nums.size();
        while (first != last)
        {
            int mid = first + (last - first) / 2;
            if (nums[first] > nums[mid])
            {
                // 说明最小值只可能出现在first和mid之间
                // 并且可以是mid，不能是first
                // 故区间为[first+1, mid]，注意区间表示为[first, last)
                // first = first + 1
                // last = mid + 1
                first++;
                last = mid + 1;
            }
            else if (nums[mid] > nums[last - 1])
            {
                // 说明最小值只可能出现在mid和last-1之间
                // 并且可以是last-1，不能是mid
                // 故区间为[mid+1, last)，注意区间表示为[first, last)
                // first = mid + 1
                first = mid + 1;
            }
            else
            // nums[first] < nums[mid] < nums[last-1]
            // 此情况发生时，整个数组严格有序，那么最小的直接就是nums[first]
            {
                return nums[first];
            }
        }
        return nums[first];
    }
};