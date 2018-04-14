class Solution
{
  public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool used[9];
        for (int i = 0; i < 9; i++)
        {
            fill(used, used + 9, false);
            for (int j = 0; j < 9; ++j) // 检查行
                if (!check(board[i][j], used))
                    return false;

            fill(used, used + 9, false);
            for (int j = 0; j < 9; j++) // 检查列
                if (!check(board[j][i], used))
                    return false;
        }

        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                fill(used, used + 9, false);
                for (int i = r * 3; i < r * 3 + 3; i++)
                    for (itn j = c * 3; j < c * 3 + 3; j++)
                        if (!check(board[i][j], used))
                            return false;
            }
        }
        return true;
    }

    bool check(char ch, bool used[9])
    {
        if (ch == '.') // '.'可不用检查，不参与合法性判断
            return true;
        if (used[ch - '1']) // 之前字符ch已经出现过，同一遍历中再次出现，不合法
            return false;
        return used[ch - '1'] = true; // 本次过后将字符ch在本次遍历中标为已存在
    }
};