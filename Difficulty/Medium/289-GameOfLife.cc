// 题目要求：
// 给定矩阵m×n个方格(cell)
// 每个cell都有一个初始状态1，表示存活(live)，或初始状态0，表示死亡(dead)
// 规定每个cell与8个相邻cell(左右、上下、对角线相邻)交互得到其下一个状态的规则如下：
//（1）如本cell当前状态为存活，若相邻cell里存活数量少于2个，则本cell接下来会死亡(under-population)
//（2）如本cell当前状态为存活，若相邻cell里存活数量为2～3个，则本cell接下来继续存活
//（3）如本cell当前状态为存活，若相邻cell里存活数量超过3个，则本cell接下来也会死亡(over-population)
//（4）如本cell当前状态为死亡，若相邻cell里存活数量正好为3个，则本cell接下来会复活(reproduction)
// 给定初始矩阵，计算得到该矩阵的下一个状态，要求in-place就地修改矩阵得到
class Solution
{
  public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size(), n = m ? board[0].size() : 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int count = 0;
                for (int I = max(i - 1, 0); I < min(i + 2, m); ++I)
                    for (int J = max(j - 1, 0); J < min(j + 2, n); ++J)
                        count += board[I][J] & 1;
                if (count == 3 || count - board[i][j] == 3)
                    board[i][j] |= 2;
            }
        }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] >>= 1;
    }
};

/*
状态: 前一位表示下一代的状态,后一位表示当前的状态
00: 死->死
10: 死->活
01: 活->死
11: 活->活
*/
class Solution
{
  public:
    void gameOfLife(vector<vector<int>> &board)
    {
        const int m = board.size();
        const int n = m ? board[0].size() : 0;

        // 坐标数组，用于与(i,j)分别相加减，得到以(i,j)为中心的九宫格中其他cell的坐标
        // {0,0}就是自身
        int d[][2] = {
            {1, -1},  // (i,j) + (1,-1) => (i+1,j-1)，即右上cell
            {1, 0},   // (i,j) + (1,0) => (i+1, j)，即右cell
            {1, 1},   // (i,j) + (1,1) => (i+1,j+1)，即右下cell
            {0, -1},  // (i,j) + (0,-1) => (i, j-1)，即上cell
            {0, 1},   // (i,j) + (0,1) => (i,j+1)，即下cell
            {-1, -1}, // (i,j) + (-1,-1) => (i-1,j-1)，即左上cell
            {-1, 0},  // (i,j) + (-1,0) => (i-1,j)，即左cell
            {-1, 1}}; // (i,j) + (-1,1) => (i-1,j+1)，即左下cell

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // 遍历以当前cell(i,j)为中心的九宫格中的相邻元素
                int live = 0; // 计数当前以cell(i,j)为中心的九宫格中存活cell数量
                for (int k = 0; k < 8; k++)
                {
                    int x = d[k][0] + i;
                    int y = d[k][1] + j;
                    if (x < 0 || x >= m || y < 0 || y >= n) // 坐标范围为0<=x<m，0<=y<n
                        continue;
                    if (board[x][y] & 1) // 当前相邻元素存活，计数+1
                        live++;
                }
                // 当前cell(i,j)死亡
                if (board[i][j] == 0)
                {
                    if (live == 3)       // 有恰好三个相邻cell存活时才能复活
                        board[i][j] = 2; // 2 -> 10，低位0表示之前是死的，高位1表示接下来复活了
                }
                // 当前cell(i,j)存活
                else
                {
                    if (live < 2 || live > 3)
                        // 少于两个相邻存活cell(under-population)或多于3个相邻存活cell(over-population)时死亡
                        board[i][j] = 1; // 1 -> 01，低位1表示之前是活的，高位0表示接下来死了
                    else                 // 相邻存活cell数量2~3
                        board[i][j] = 3; // 3 -> 11，低位1表示之前是活的，高位1表示接下来仍存活
                }
            }
        }

        // 每个cell都已经存储了新状态信息，右移一位除去各个cell数值的低位，只保留高位即可
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                board[i][j] >>= 1;
            }
        }
    }
};

class Solution
{
  public:
    void gameOfLife(vector<vector<int>> &board)
    {
        if (board.empty())
            return;
        const int m = board.size();
        const int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                check(board, i, j, i + 1, j - 1);
                check(board, i, j, i + 1, j);
                check(board, i, j, i + 1, j + 1);
                check(board, i, j, i, j + 1);
                if (board[i][j] >= 5 && board[i][j] <= 7)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }

  private:
    void check(vector<vector<int>> &board, int i, int j, int a, int b)
    {
        const int m = board.size();
        const int n = board[0].size();
        if (a >= m || b < 0 || b >= n)
            return;
        if (board[i][j] % 2 != 0)
            board[a][b] += 2;
        if (board[a][b] % 2 != 0)
            board[i][j] += 2;
    }
};