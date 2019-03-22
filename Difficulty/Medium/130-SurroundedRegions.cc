class Solution
{
  public:
    void solve(vector<vector<char>> &board)
    {
        if (board.empty())
            return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
                mark(i, 0, board);
            if (board[i][n - 1] == 'O')
                mark(i, n - 1, board);
        }
        for (int j = 1; j < n - 1; j++)
        {
            if (board[0][j] == 'O')
                mark(0, j, board);
            if (board[m - 1][j] == 'O')
                mark(m - 1, j, board);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '#')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
    void mark(int x, int y, vector<vector<char>> &board)
    {
        queue<pair<int, int>> toVisit;
        toVisit.push(make_pair(x, y));
        board[x][y] = '#';
        while (!toVisit.empty())
        {
            int size = toVisit.size();
            for (int i = 0; i < size; i++)
            {
                pair<int, int> cur = toVisit.front();
                toVisit.pop();
                update(board, toVisit, cur.first, cur.second);
            }
        }
    }
    void update(vector<vector<char>> &board, queue<pair<int, int>> &q, int x, int y)
    {
        if (x - 1 >= 0 && board[x - 1][y] == 'O')
        {
            board[x - 1][y] = '#';
            q.push(make_pair(x - 1, y));
        }
        if (x + 1 < board.size() && board[x + 1][y] == 'O')
        {
            board[x + 1][y] = '#';
            q.push(make_pair(x + 1, y));
        }
        if (y - 1 >= 0 && board[x][y - 1] == 'O')
        {
            board[x][y - 1] = '#';
            q.push(make_pair(x, y - 1));
        }
        if (y + 1 < board[0].size() && board[x][y + 1] == 'O')
        {
            board[x][y + 1] = '#';
            q.push(make_pair(x, y + 1));
        }
    }
};

// class Solution
// {
//   public:
//     void solve(vector<vector<char>> &board)
//     {
//         if (board.empty())
//             return;

//         const int m = board.size();
//         const int n = board[0].size();

//         for (int i = 0; i < n; i++)
//         {
//             bfs(board, 0, i);
//             bfs(board, m - 1, i);
//         }

//         for (int j = 1; j < m; j++)
//         {
//             bfs(board, j, 0);
//             bfs(board, j, n - 1);
//         }

//         for (int i = 0; i < m; i++)
//             for (int j = 0; j < n; j++)
//                 if (board[i][j] == '0')
//                     board[i][j] = 'X';
//                 else if (board[i][j] == '+')
//                     board[i][j] = '0';
//     }

//   private:
//     void bfs(vector<vector<char>> &board, int i, int j)
//     {
//         typedef pair<int, int> state_t;
//         queue<state_t> q;
//         const int m = board.size();
//         const int n = board[0].size();

//         auto state_is_valid = [&](const state_t &s) {
//             const int x = s.first;
//             const int y = s.second;
//             if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != '0')
//                 return false;

//             return true;
//         };

//         auto state_extend = [&](const state_t &s) {
//             vector<state_t> result;
//             const int x = s.first;
//             const int y = s.second;

//             // 上下左右
//             const state_t new_states[4] = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};

//             for (int k = 0; k < 4; k++)
//             {
//                 if (state_is_valid(new_states[k]))
//                 {
//                     // 既有标记功能又有去重功能
//                     board[new_states[k].first][new_states[k].second] = '+';
//                     result.push_back(new_states[k]);
//                 }
//             }
//             return result;
//         };

//         state_t start = {i, j};
//         if (state_is_valid(start))
//         {
//             board[i][j] = '+';
//             q.push(start);
//         }

//         while (!q.empty())
//         {
//             auto cur = q.front();
//             q.pop();
//             auto new_states = state_extend(cur);
//             for (auto s : new_states)
//                 q.push(s);
//         }
//     }
// };