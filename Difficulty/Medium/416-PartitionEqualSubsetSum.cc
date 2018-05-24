class Solution
{
  public:
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum >> 1; // 即子序列和为总和的一半

        if (sum & 1) // 全部数字和必须为偶数，才能均分为两个和相等的子序列
            return false;

        vector<int> dp(target + 1, 0); // 数组元素仅为0或1，表示可否达到下标对应的和，如dp[i]即能否是nums中一个子序列的和
        dp[0] = 1;                     // 空子序列即可达到和为0
        for (auto num : nums)
            // 当前遍历的数为num，如能构成一个和为i-num的子序列，则加上该num，就可构成一个和为i的子序列
            // 即状态dp[i]总是依赖前面的某个状态dp[i-num]
            for (int i = target; i >= num; i--)
                dp[i] = dp[i] || dp[i - num];

        return dp[target];
    }
};