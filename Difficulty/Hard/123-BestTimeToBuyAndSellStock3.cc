/* 
    动态规划
    设状态f(i)为区间[0,i]的最大利润，其中0<=i<=n-1
    状态g(i)表示区间[i,n-1]的最大利润，其中0<=i<=n-1
    最终答案为max{f(i)+g(i)},0<=i<=n-1
 */
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        // 判断边界条件总是个好习惯
        if (prices.size() < 2)
            return 0;

        const int n = prices.size();

        vector<int> f(n, 0);
        vector<int> g(n, 0);

        for (int i = 1, valley = prices[0]; i < n; ++i)
        {
            valley = min(valley, prices[i]);
            f[i] = max(f[i - 1], prices[i] - valley);
        }
        for (int i = n - 2, peak = prices[n - 1]; i >= 0; --i)
        {
            peak = max(peak, prices[i]);
            g[i] = max(g[i], peak - prices[i]);
        }
        int max_profit = 0;
        for (int i = 0; i < n; ++i)
            max_profit = max(max_profit, f[i] + g[i]);
        return max_profit;
    }
};