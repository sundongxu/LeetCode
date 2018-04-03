/* 
    时间复杂度O(n)，空间复杂度O(1)
 */

// 法一：异或，出现偶数次的都可清零
class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;
        for (int i : nums)
            result ^= i;
        return result;
    }
};

// 法二：异或 + STL
class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};