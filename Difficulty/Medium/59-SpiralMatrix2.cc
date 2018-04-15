#include <iostream>
#include <vector>

using namespace std;

// 和54题解法一致
// 空间复杂度O(n^2)，时间复杂度O(n^2)
class Solution
{
  public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n, 0));
        if (n == 0)
            return result;

        int beginX = 0, endX = n - 1; // 横坐标范围，其实对应的是列数
        int beginY = 0, endY = n - 1; // 纵坐标范围，其实对应的是行数

        int cur = 1;

        while (true)
        {
            // 从左到右，访问完当前行，则下一次纵向访问时起点或终点的Y坐标应为当前Y+1
            for (int j = beginX; j <= endX; ++j)
                result[beginY][j] = cur++;
            if (++beginY > endY)
                break;

            // 从上往下，访问完当前列，则下一次横向访问时起点或终点的X坐标应为当前X-1
            for (int i = beginY; i <= endY; ++i)
                result[i][endX] = cur++;
            if (beginX > --endX)
                break;

            // 从右往左，访问完当前行，则下一次纵向访问时起点或终点的Y坐标应为当前Y-1
            for (int j = endX; j >= beginX; --j)
                result[endY][j] = cur++;
            if (beginY > --endY)
                break;

            // 从下往上，访问完当前列，则下一次横向访问时起点或终点的X坐标应为当前X+1
            for (int i = endY; i >= beginY; --i)
                result[i][beginX] = cur++;
            if (++beginX > endX)
                break;
        }
        return result;
    }
};

// 稍微简单些的解法
// 空间复杂度O(n^2)，时间复杂度O(n^2)
class Solution
{
  public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n, 0));
        if (n == 0)
            return result;
        int begin = 0, end = n - 1;
        int num = 1;

        while (begin < end)
        {
            for (int j = begin; j < end; ++j)
                result[begin][j] = num++;
            for (int i = begin; i < end; ++i)
                result[i][end] = num++;
            for (int j = end; j > begin; j--)
                result[end][j] = num++;
            for (int i = end; i > begin; i--)
                result[i][begin] = num++;
            ++begin;
            --end;
        }

        if (begin == end) // 中心元素
            result[begin][end] = num;

        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> res = s.generateMatrix(3);
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j];
            if (j < res[0].size() - 1)
                cout << ",";
        }

        cout << "]" << endl;
    }

    return 0;
}