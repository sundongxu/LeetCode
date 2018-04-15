// 时间复杂度O(m*n)，空间复杂度O(m+n)，in-place就地更改
class Solution
{
  public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        const size_t m = matrix.size();    // 行数
        const size_t n = matrix[0].size(); // 列数
        vector<bool> row(m, false);        // 标记该行是否存在0
        vector<bool> col(n, false);        // 标记该列是否存在0

        for (size_t i = 0; i < m; i++)
            for (size_t j = 0; j < n; j++)
                if (matrix[i][j] == 0)
                    row[i] = col[j] = true;
        for (size_t i = 0; i < m; i++)
            if (row[i]) // 同一行元素是连续存储的，可用fill直接赋值
                fill(&matrix[i][0], &matrix[i][0] + n, 0);

        for (size_t j = 0; j < n; j++)
            if (col[j]) // 同一列元素不是连续存储的，只能遍历每一行
                for (size_t i = 0; i < m; i++)
                    matrix[i][j] = 0;
    }
};

// 时间复杂度O(m*n)，空间复杂度O(1)，in-place就地更改
// 思想：复用第一行和第一列
class Solution
{
  public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        const size_t m = matrix.size();    // 行数
        const size_t n = matrix[0].size(); // 列数
        bool row_has_zero = false;         // 第一行是否存在0
        bool col_has_zero = false;         // 第一列是否存在0

        for (size_t i = 0; i < n; i++) // 遍历第一行
            if (matrix[0][i] == 0)
            {
                row_has_zero = true;
                break;
            }

        for (size_t i = 0; i < m; i++) // 遍历第一列
            if (matrix[i][0] == 0)
            {
                col_has_zero = true;
                break;
            }

        for (size_t i = 1; i < m; i++)     // 遍历每一行，除了第一行
            for (size_t j = 1; j < n; j++) // 遍历每一列，出了第一列
                if (matrix[i][j] == 0)
                {
                    // 遇到一个为0的元素
                    // 就将其所在行第一列元素和所在列第一行元素置为0
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }

        // 将第一个元素为0的行和列都置为0
        for (size_t i = 1; i < m; i++)
            for (size_t j = 1; j < n; j++)
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;

        // 根据标志位决定是否将第一行置为0
        if (row_has_zero)
            for (size_t i = 0; i < n; i++)
                matrix[0][i] = 0;

        // 根据标志位决定是否将第一列置为0
        if (col_has_zero)
            for (size_t i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};