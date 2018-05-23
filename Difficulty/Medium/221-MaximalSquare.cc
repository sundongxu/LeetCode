class Solution
{
  public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty()) // 短路性质
            return 0;
        int n1 = matrix.size(), n2 = matrix[0].size(), ans = 0;
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 1; i <= n1; ++i)
        {
            for (int j = 1; j <= n2; ++j)
            {
                if (matrix[i - 1][j - 1] == '1')
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                ans = max(ans, dp[i][j]); // 记录最大边长
            }
        }
        return ans * ans;
    }
};