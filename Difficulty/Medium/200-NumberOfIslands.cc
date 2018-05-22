class Solution
{
  public:
    int searchAt(vector<vector<char>> &grid, int x, int y)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size() || grid[x][y] == '0')
            return 0;
        // grid[x][y] = 1 才去判断是不是island
        grid[x][y] = '0';  
        // 会把同一个island中的所有land(即为1的方格)都变成0，所以每次统计计数的时候就会只把这个大的island统计一次
        // 遍历到某个land时，会把上下左右四个land都置为0
        searchAt(grid, x + 1, y);
        searchAt(grid, x, y + 1);
        searchAt(grid, x - 1, y);
        searchAt(grid, x, y - 1);
        return 1;
    }

    int numIslands(vector<vector<char>> &grid)
    {
        unsigned islands = 0;
        for (int x = 0; x < grid.size(); x++)
        {
            for (int y = 0; y < grid[x].size(); y++)
            {
                islands += searchAt(grid, x, y);
            }
        }
        return islands;
    }
};