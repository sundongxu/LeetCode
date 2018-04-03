/* 
    贪心，低进高出，把所有正的相邻差价相加
    只要上涨的时候就持有，赶上所有的行情...要现实世界这么美好就好了...
    让我哭一会...
 */
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        // 边界条件
        if (prices.size() < 2)
            return 0;
        int sum = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int diff = prices[i] - prices[i - 1];
            if (diff > 0)
                sum += diff;
        }
        return sum;
    }
};