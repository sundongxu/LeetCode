class Solution
{
  public:
    vector<vector<int>> getRow(int rowIndex)
    {
        vector<vector<int>> result(rowIndex + 1);
        for (int i = 0; i < rowIndex; i++) // 遍历每一行
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || i == j)
                    result[i].push_back(1);
                else
                    result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
        return result[rowIndex];
    }
};