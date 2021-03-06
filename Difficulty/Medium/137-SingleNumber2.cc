/* 
    时间复杂度O(n)，空间复杂度O(1)
 */

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        const int W = sizeof(int) * 8; // 一个整数的bit数，即整数字长
        int count[W];                  // count[i]表示在第i位出现1的次数
        fill_n(&count[0], W, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < W; j++)
            {
                count[j] += (nums[i] >> j) & 1;
                count[j] %= 3;
            }
        }
        int result = 0;
        for (int i = 0; i < W; i++)
        {
            result += (count[i] << i);  // 因为最后只剩一个数，所以count[i]要么为0，要么为1
        }
        return result;
    }
};

// 法二
class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        int one = 0, two = 0, three = 0;
        for (auto i : nums)
        {
            two |= (one & i);
            one ^= i;
            three = ~(one & two);
            one &= three;
            two &= three;
        }
        return one;
    }
};