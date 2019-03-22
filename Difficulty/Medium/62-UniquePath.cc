/* 
    My Version
    直接上动态规划
    状态转移方程：f(i,j) = f(i-1,j) + f(i,j-1)
 */
class Solution
{
  public:
    int uniquePaths(int m, int n)
    {
        int f[m][n];
        if (m < 1 || n < 1) // 终止条件
            return 0;
        if (m == 1 && n == 1) // 收敛条件
            return 1;

        for (int i = 0; i < m; i++)
            f[i][0] = 1;

        for (int j = 1; j < n; j++)
            f[0][j] = 1;

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                f[i][j] = f[i - 1][j] + f[i][j - 1];

        return f[m - 1][n - 1];
    }
};

/* 
    先来递归，即深度搜索
    TLE，小集合可以过，大集合超时
    问题在于重复计算太多
 */
class Solution
{
  public:
    int uniquePaths(int m, int n)
    {
        if (m < 1 || n < 1) // 终止条件
            return 0;
        if (m == 1 && n == 1) // 收敛条件
            return 1;
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};

/* 
    深搜 + 缓存，即备忘录法
    简单来说就是记住前面有效的计算结果在后面深度搜索中有机会直接用，解决TLE问题
    时间复杂度O(n^2)，空间复杂度O(n^2)
*/
class Solution
{
  public:
    int uniquePaths(int m, int n)
    {
        // f[x][y]表示从(0,0)到(x,y)的路径条数
        f = vector<vector<int>>(m, vector<int>(n, 0));
        f[0][0] = 1; // 很关键，不然之后到任意位置的路径条数都是0...
        return dfs(m - 1, n - 1);
    }

  private:
    vector<vector<int>> f;
    int dfs(int x, int y)
    {
        if (x < 0 || y < 0) // 数据非法，终止条件
            return 0;

        if (x == 0 && y == 0) // 回到起点，收敛条件
            return f[0][0];

        if (f[x][y] > 0) // 记忆，如果之前算过了，就不再算，直接返回
            return f[x][y];
        else
            return f[x][y] = dfs(x - 1, y) + dfs(x, y - 1);
    }
};

/*
    既然可以用备忘录法自顶向下解决，也一定可以用动规自底向上解决
    这回用滚动数组节省空间
 */
class Solution
{
  public:
    int uniquePaths(int m, int n)
    {
        vector<int> f(n, 0);
        f[0] = 1;
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                // 左边的f[j]，表示更新后的f[j]，是当前行即第i行的路径数，与公式中的f[i][j]对应
                // 右边的f[j]，表示老的f[j]，是上一行即第i-1行的路径数，与公式中的f[i-1][j]对应
                // 因为每一次老的f[j](即f[i-1][j])在本次使用之后之后都不再使用所以可以覆盖旧值
                f[j] = f[j] + f[j - 1];
        return f[n - 1];
    }
};
