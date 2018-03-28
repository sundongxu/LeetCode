/*  
    又是动态规划！
    自己完成的第二道DP问题哈哈哈，还优化了空间(原方法是用)
    状态转移方程：f(i,j) = min(f(i-1,j), f(i,j-1)) + (i,j)
 */

class Solution
{
  public:
    int minPathSum(vector<vector<int>> &grid)
    {
        // 边界条件，判空
        if (grid.size() == 0)
            return 0;
        if (grid[0].size() == 0)
            return 0;
        // 状态转移方程：f(i,j) = min(f(i-1,j), f(i,j-1)) + (i,j)
        const int row_count = grid.size();
        const int col_count = grid[0].size();

        for (int i = 1; i < row_count; i++) // 这里也要记住 i-1 ≥ 0 的条件，否则出现数组越界，null pointer
            grid[i][0] += grid[i - 1][0];
        for (int j = 1; j < col_count; j++)
            grid[0][j] += grid[0][j - 1];

        for (int i = 1; i < row_count; i++)
            for (int j = 1; j < col_count; j++)
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        return grid[row_count - 1][col_count - 1];
    }
};

/* 
    别人家的思路
    动规 + 滚动数组
    看来看去还是我的比较好，节省空间
 */
class Solution
{
  public:
    int minPathSum(vector<vector<int>> &grid)
    {
        const int m = grid.size();
        const int n = grid[0].size();
        int f[n];
        fill(f, f + n, INT_MAX); // 初始值是INT_MAX，因为后面用了min
        f[0] = 0;
        for (int i = 0; i < m; i++)
        {
            f[0] += grid[i][0];
            for (int j = 1; j < n; j++)
            {
                // 右边的f[j]，表示更新后的f[j]，与公式中的f[i][j]对应
                // 右边的f[j]，表示老的f[j]，与公式中的f[i-1][j]对应
                f[j] = min(f[j - 1], f[j]) + grid[i][j];
            }
        }
        return f[n - 1];
    }
};
