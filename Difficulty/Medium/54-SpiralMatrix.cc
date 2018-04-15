// 时间复杂度O(n^2)，空间复杂度O(1)
class Solution
{
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        if (matrix.empty()) // 边界条件
            return result;

        int beginX = 0, endX = matrix[0].size() - 1; // 横坐标范围，其实对应的是列数
        int beginY = 0, endY = matrix.size() - 1;    // 纵坐标范围，其实对应的是行数

        while (true)
        {
            // 从左到右，访问完当前行，则下一次纵向访问时起点或终点的Y坐标应为当前Y+1
            for (int j = beginX; j <= endX; ++j)
                result.push_back(matrix[beginY][j]);
            if (++beginY > endY)
                break;

            // 从上往下，访问完当前列，则下一次横向访问时起点或终点的X坐标应为当前X-1
            for (int i = beginY; i <= endY; ++i)
                result.push_back(matrix[i][endX]);
            if (beginX > --endX)
                break;

            // 从右往左，访问完当前行，则下一次纵向访问时起点或终点的Y坐标应为当前Y-1
            for (int j = endX; j >= beginX; --j)
                result.push_back(matrix[endY][j]);
            if (beginY > --endY)
                break;

            // 从下往上，访问完当前列，则下一次横向访问时起点或终点的X坐标应为当前X+1
            for (int i = endY; i >= beginY; --i)
                result.push_back(matrix[i][beginX]);
            if (++beginX > endX)
                break;
        }
        return result;
    }
};