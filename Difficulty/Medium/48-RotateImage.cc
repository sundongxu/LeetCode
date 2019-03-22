// 沿副对角线翻转，再沿水平中线翻转
//  时间复杂度O(n^2)，空间复杂度O(1)
class Solution
{
  public:
    void rotate(vector<vector<int>> &matrix)
    {
        const int n = matrix.size();
        for (int i = 0; i < n; ++i) // 先沿副对角线翻转
            for (int j = 0; j < n - i; ++j)
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
        for (int i = 0; i < n / 2; ++i) // 再沿水平中线翻转
            for (int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n - 1 - i][j]);
    }
};

class Solution
{
  public:
    void rotate(vector<vector<int>> &matrix)
    {
        const int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) // 先沿水平中线翻转
            for (int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n - 1 - i][j]);
        for (int i = 0; i < n; ++i) // 再沿着主对角线翻转
            for (int j = i + 1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};