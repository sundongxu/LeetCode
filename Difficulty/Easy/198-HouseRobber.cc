/* 
    求最大值，前后有状态关联
    动态规划
    (1)定义状态f[i]，为抢劫前i个房子可得到的最大值(最多钱)
    (2)定义状态转移函数：
    对于当前状态f[i]，
    ① 如果不抢劫第i个房子，那么抢完第i个房子的最大值就是抢完第i-1个房子的最大值，即上一个状态对应f[i-1]，
    ② 如果抢劫第i个房子，那么抢完第i个房子的最大值应为抢完第i-2个房子的最大值加上第i个房子中的钱，即f[i-2] + nums[i]
    故状态转换方程为：f[i] = max{f[i-1], f[i-2] + nums[i]}
    定义起点，即i=0与i=1的情况
    结果则取终点f[n]
 */
class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int n = nums.size();
        vector<int> f(n + 1, 0);
        f[0] = 0;
        f[1] = nums[0];

        for (int i = 2; i <= n; i++)
            f[i] = max(f[i - 1], f[i - 2] + nums[i - 1]);
        return f[n];
    }
};

/* 
    滚动数组优化空间，观察状态转移方程
    可发现 f[i] 只依赖于 f[i-1] 和 f[i-2]
    所以大小为3的数组就够了。然后通过取模3-1=2来不断更新数组，求得结果
 */
class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int n = nums.size();
        vector<int> f(3, 0);
        f[0] = 0;
        f[1] = nums[0];

        for (int i = 2; i <= n; i++)
            f[i % 2] = max(f[(i - 1) % 2], f[(i - 2) % 2] + nums[i - 1]);
        return f[n % 2];
    }
};