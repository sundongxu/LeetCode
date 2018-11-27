/* 
    暴力会超时
    用贪心，分别找到价格最低和最高的一天，低进高出，注意最低的一天要在最高的一天之前
    把原始价格序列变成差分序列
    
 */
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        // 边界条件
        if (prices.size() < 2)
            return 0;
        int max_profit = 0;
        int cur_min = prices[0]; // 当前最小
        for (int i = 1; i < prices.size(); i++)
        {
            max_profit = max(max_profit, prices[i] - cur_min); // 每步都得到当前最大利润
            // 更新当前最小，为之后当前最高减去当前最小计算最大盈利做准备
            cur_min = min(cur_min, prices[i]);
        }
        return max_profit;
    }
};