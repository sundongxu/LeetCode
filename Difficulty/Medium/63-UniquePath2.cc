// 62题中第一行第一列都是1
// 但本题不同，第一列如果某行有障碍物，则后面的行全为0
// 依然动规+滚动数组
// 时间复杂度O(n^2)，空间复杂度O(n)
class Solution
{
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) // 边界条件，起点和终点都有障碍物，不可到达
            return 0;

        vector<int> f(n, 0);
        f[0] = 1;

        for (int i = 0; i < m; i++)
        {
            f[0] = f[0] == 0 ? 0 : (obstacleGrid[i][0] ? 0 : 1);
            for (int j = 1; j < n; j++)
                f[j] = obstacleGrid[i][j] ? 0 : (f[j] + f[j - 1]);
        }
        return f[n - 1];
    }
};

// 深搜+缓存，即备忘录法
class Solution
{
  public:
    int uniquePathsWithObstacles(const vector<vector<int>> &obstacleGrid)
    {
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])
            return 0;
        f = vector<vector<int>>(m, vector<int>(n, 0));
        f[0][0] = obstacleGrid[0][0] ? 0 : 1;
        return dfs(obstacleGrid, m - 1, n - 1);
    }

  private:
    vector<vector<int>> f; // 缓存

    // 返回从(0,0)到(x,y)的路径总数
    int dfs(const vector<vector<int>> &obstacleGrid,
            int x, int y)
    {
        if (x < 0 || y < 0)
            return 0; // 数据非法，终止条件

        if (obstacleGrid[x][y]) // (x,y)是障碍点
            return 0;

        if (x == 0 and y == 0)
            return f[0][0]; // 回到起点，收敛条件

        if (f[x][y] > 0)
            return f[x][y];
        else
            return f[x][y] = dfs(obstacleGrid, x - 1, y) +
                             dfs(obstacleGrid, x, y - 1);
    }
};