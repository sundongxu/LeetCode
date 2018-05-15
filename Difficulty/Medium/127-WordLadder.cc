class Solution
{
  private:
    bool oneDiff(string &a, string &b)
    {
        if (a.size() != b.size())
            return false;
        int count = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] == b[i])
                ++count;
        }
        return a.size() - count == 1;
    }

  public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // min为最短路径长度(结点数)
        // total为当轮循环中wordList中与当前词current仅相差一个字母的单词个数
        // remain为队列当前剩余元素个数
        // level为遍历层数，最后某次循环中出队找到一个current == endWord，则最短路径 = 遍历层次数 + 1
        int min = 0, total = 0, remain = 1, level = 0;
        queue<string> q;
        q.push(beginWord);
        while (!q.empty())
        {
            string current = q.front();
            if (current == endWord)
            {
                min = ++level;
                break;
            }
            --remain; // 出队，队列元素个数减一
            q.pop();
            if (!wordList.empty())
            {
                for (long i = wordList.size() - 1; i >= 0; --i)
                {
                    // 从尾到头找与当前词current仅相差一位的单词
                    if (oneDiff(wordList[i], current))
                    {
                        q.push(wordList[i]);
                        ++total; //
                        wordList.erase(wordList.begin() + i);
                    }
                }
            }
            if (!remain && total > 0)
            {
                ++level;        // 本轮循环结束，遍历层数加一
                remain = total; // 本轮循环中又新入队了total个单词，remain计数队列元素个数
                total = 0;      // 本轮循环结束，复位
            }
        }
        return min;
    }
};

// // 求最短路径，用广度优先搜索
// struct state_t
// {
//     string word;
//     int level;

//     state_t()
//     {
//         word = "";
//         level = 0;
//     }

//     state_t(const string &word, int level)
//     {
//         this->word = word;
//         this->level = level;
//     }

//     bool operator==(const state_t &other) const
//     {
//         return this->word == other.word;
//     }
// };

// namespace std
// {
// template <>
// struct hash<state_t>
// {
//   public:
//     size_t operator()(const state_t &s) const
//     {
//         return str_hash(s.word);
//     }

//   private:
//     std::hash<std::string> str_hash;
// };
// } // namespace std

// class Solution
// {
//   public:
//     int ladderLength(string beginWord, string endWord, vector<string> &wordList)
//     {
//         if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
//             return 0;

//         queue<state_t> q;
//         unordered_set<state_t> visited; // 判重

//         auto state_is_valid = [&](const state_t &s) { return find(wordList.begin(), wordList.end(), s.word) != wordList.end() || s.word == endWord; };

//         auto state_is_target = [&](const state_t &s) { return s.word == endWord; };

//         auto state_extend = [&](const state_t &s) {
//             unordered_set<state_t> result;
//             for (int i = 0; i < s.word.size(); i++)
//             {
//                 state_t new_state(s.word, s.level + 1);
//                 for (char c = 'a'; c <= 'z'; c++)
//                 {
//                     // 防止同字母替换
//                     if (c == new_state.word[i])
//                         continue;
//                     swap(c, new_state.word[i]);
//                     if (state_is_valid(new_state) && visited.find(new_state) == visited.end())
//                         result.insert(new_state);
//                     swap(c, new_state.word[i]); // 恢复该单词
//                 }
//             }
//             return result;
//         };

//         state_t start_state(start, 0);
//         q.push(start_state);
//         visited.insert(start_state);
//         while (!q.empty())
//         {
//             const auto state = q.front();
//             q.pop();

//             if (state_is_target(state))
//                 return state.level + 1;

//             const auto &new_states = state_extend(state);
//             for (const auto &new_state : new_states)
//             {
//                 q.push(new_state);
//                 visited.insert(new_states);
//             }
//         }
//         return 0;
//     }
// };