/* 
    之前是线性序列，动规每步贪心去做就好，现在成环，首尾相接
    连成圈说明第一间房子和最后一间房子不能同时抢，这如何在转换方程中体现呢？
    其实用两个数组分别表示不包含第一间和不包含最后一间两种情况就好了
 */
class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0) // 边界条件别忘了
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int len = nums.size();
        vector<int> dp1(len + 1, 0); // 可抢第一个房子，不能抢最后一个房子
        vector<int> dp2(len + 1, 0); // 不抢第一个房子，可以抢最后一个房子
        dp1[0] = 0;
        dp1[1] = nums[0];
        dp2[0] = 0;
        dp2[1] = 0;

        for (int i = 2; i <= len; i++)
        {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i - 1]);
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i - 1]);
        }
        dp1[len] = dp1[len - 1]; // dp1代表的是不抢最后一间房子
        return max(dp1[len], dp2[len]);
    }
};

// 动规 + 滚动数组
class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0) // 边界条件别忘了
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int len = nums.size();
        vector<int> dp1(3, 0); // 可抢第一个房子，不能抢最后一个房子
        vector<int> dp2(3, 0); // 不抢第一个房子，可以抢最后一个房子
        dp1[0] = 0;
        dp1[1] = nums[0];
        dp2[0] = 0;
        dp2[1] = 0;

        for (int i = 2; i <= len; i++)
        {
            dp1[i % 2] = max(dp1[(i - 1) % 2], dp1[(i - 2) % 2] + nums[i - 1]);
            dp2[i % 2] = max(dp2[(i - 1) % 2], dp2[(i - 2) % 2] + nums[i - 1]);
        }
        dp1[len % 2] = dp1[(len - 1) % 2]; // dp1代表的是不抢最后一间房子
        return max(dp1[len % 2], dp2[len % 2]);
    }
};