// 动态规划问题～
// 状态转移方程为：
// cost[i][j] = min(cost[i-1][j-1] + cost[i-1][j]) + triangle[i][j]
// 第(i,j)元素在上一行中相邻的元素为(i-1,j-1) 和 (i-1,j)
// 特别要注意，要处理边界问题，因为靠边的元素在上一行中只有一个相邻元素
// 自己写出来的哟，哈哈哈~ 第一道自己完成的动态规划，虽然很简单，但一步一步一个脚印～
class Solution
{
  public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        // 直接在triangle上面操作，将原本位置上的元素值改为从顶端到此结点的最短路径和
        int lower = 0, upper = 0;
        for (int i = 1; i < triangle.size(); i++)        // 从第一行起，遍历每一行
            for (int j = 0; j < triangle[i].size(); j++) // 遍历每一列
            {
                lower = max(0, j - 1);
                upper = min(j, static_cast<int>(triangle[i - 1].size()) - 1);
                // 状态转移方程
                triangle[i][j] += min(triangle[i - 1][lower], triangle[i - 1][upper]);
            }
        // 遍历最后一行，找出最小的返回
        int minPathSum = INT_MAX;
        for (int j = 0; j < triangle[triangle.size() - 1].size(); j++)
            if (minPathSum > triangle[triangle.size() - 1][j])
                minPathSum = triangle[triangle.size() - 1][j];
        return minPathSum;
    }
};