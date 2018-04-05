/* 
    求最大值，前后有状态关联
    动态规划
 */
class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int len = nums.size();
        vector<int> f(len + 1, 0);
        f[0] = 0;
        f[1] = nums[0];

        for (int i = 2; i <= len; i++)
            f[i] = max(f[i - 1], f[i - 2] + nums[i - 1]);
        return f[len];
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
        int len = nums.size();
        vector<int> f(3, 0);
        f[0] = 0;
        f[1] = nums[0];

        for (int i = 2; i <= len; i++)
            f[i % 2] = max(f[(i - 1) % 2], f[(i - 2) % 2] + nums[i - 1]);
        return f[len % 2];
    }
};