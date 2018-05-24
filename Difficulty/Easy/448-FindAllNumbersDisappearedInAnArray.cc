// 要求不能用辅助空间，时间复杂度为O(n)

// 用了O(1)的辅助空间
// First iteration to negate values at position whose equal to values appear in array.
// Second iteration to collect all position whose value is positive, which are the missing values.
// Complexity is O(n) Time and O(1) space.

class Solution
{
  public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int len = nums.size();

        for (int i = 0; i < len; i++)
        {
            int index = abs(nums[i]) - 1; // index start from 0，而nums[i]最小为1
            nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
        }
        vector<int> res;
        for (int i = 0; i < len; i++)
        {
            if (nums[i] > 0)
                res.push_back(i + 1);
        }
        return res;
    }
};