/*
    dp[i]定义为总金额amount=i时的最少硬币数额. 初始化dp数组每一个元素都为-1，表示对数额i无解，且dp[0]=0
    那么对于每个硬币，面值设为c:
    ① if i - c < 0, do nothing.
    ② if i - c >= 0 and dp[i - c] != -1, 即对总数额amount=i-c有解，dp[i] = min(dp[i], dp[i - c] + 1)
*/
class Solution
{
  public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i)
            for (auto &c : coins)
                if (i - c >= 0 && dp[i - c] != -1)
                    dp[i] = dp[i] > 0 ? min(dp[i], dp[i - c] + 1) : dp[i - c] + 1;

        return dp[amount];
    }
};