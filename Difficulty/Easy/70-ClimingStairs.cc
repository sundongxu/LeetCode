// 斐波那契数列问题
// 设f(n)，n > 2，为爬n阶楼梯的不同方法数，为了爬到第n阶楼梯，显然只有两个选择：
// (1) 先爬上n-1阶，再爬一级，对应方法数为f(n-1) * 1 = f(n-1)
// (2) 先爬上n-2阶，再爬两级，对应方法数为f(n-2) * 1 = f(n-2)
// 从而，有递推公式：f(n) = f(n-1) + f(n-2)

// Recursion Version
// Time Limit Exceeded! TLE错误
class Solution
{
  public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        else
            return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// Discussion 里面的四行code... AC
// 原谅我没有看懂...回头再说
class Solution
{
  public:
    int climbStairs(int n)
    {
        int a = 1, b = 1;
        while (n--)
            a = (b += a) - a;
        return a;
    }
};

// 尝试用动态规划，第一次 beat 100%...
// 不对，这其实叫迭代？？？...
// 很好理解啊！！！用非递归的方式计算f(n)(即dp[n])
class Solution
{
  public:
    int climbStairs(int n)
    {
        int *dp = new int[n + 1]; // 原因是需要dp[0]~dp[n]，共n+1个元素
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

// 再看看别人的动态规划！
class Solution
{
  public:
    int climbStairs(int n)
    {
        vector<int> res(n + 1);
        res[0] = 1;
        res[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res[n];
    }
};

// 人家说用熟了动态规划，还要想想怎么节省空间哟
class Solution
{
  public:
    int climbStairs(int n)
    {
        vector<int> res(3);
        res[0] = 1;
        res[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            res[i % 3] = res[(i - 1) % 3] + res[(i - 2) % 3];
        }
        return res[n % 3];
    }
};
