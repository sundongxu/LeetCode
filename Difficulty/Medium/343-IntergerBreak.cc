class Solution
{
  public:
    // 总是可以拆分若干个2和若干个3之和
    // 且尽可能分解成更多的3
    // 原因：6 = 2 + 2 + 2 = 3 + 3 -> 3*3 > 2*2*2
    // O(N), O(1)
    int integerBreak(int n)
    {
        vector<int> f(4);
        f[1] = 0;
        f[2] = 1;
        for (int i = 3; i <= n; i++)
            for (int j = 2; j <= 3; j++)
                f[i % 4] = max(f[i % 4], j * max(i - j, f[(i - j) % 4])); // f[i]结果最多依赖于f[i-3]，故滚动数组大小设为4就好了

        return f[n % 4];
    }

    // 递归方法
    int integerBreak(int n)
    {
        if (n < 3) // n == 2
            return 1;
        if (n == 3)
            return 2;
        return maxSumProd(n);
    }

    int maxSumProd(int n)
    {
        return (n <= 4) ? n : 3 * maxSumProd(n - 3);
    }
};