/* 
    二维数组直接每行串接在上一行之后就是一个递增数组
    想到用二分查找，唯一注意的是mid定位在矩阵的什么位置
    mid对应的矩阵元素应该为matrix[mid / n][mid % n]
 */
class Solution
{
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
            return false;
        const size_t m = matrix.size();
        const size_t n = matrix.front().size();
        int first = 0;
        int last = m * n;
        while (first < last)
        {
            int mid = first + (last - first) / 2;
            int value = matrix[mid / n][mid % n]; // mid位于第几行第几列
            if (value == target)
                return true;
            else if (value < target)
                first = mid + 1;
            else
                last = mid;
        }
        return false;
    }
};