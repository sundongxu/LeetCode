/*
    在每一步都可以判断中间结果是否为合法结果，用回溯法
    一个长度为n的字符串，有n-1个地方可以被砍断，每个地方可断可不断，因此复杂度是O(2^(n-1))
*/

class Solution
{
  public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> path; // 中间结果，一个partition方案
        dfs(s, path, result, 0);
        return result;
    }

    void dfs(string &s, vector<string> &path, vector<vector<string>> &result, int start)
    {
        if (start == s.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            if (isPalindrome(s, start, i)) // 从位置i砍一刀
            {
                path.push_back(s.substr(start, i - start + 1));
                dfs(s, path, result, i + 1); // 继续向下砍
                path.pop_back();             // 撤销上上行
            }
        }
    }

    bool isPalindrome(const string &s, int start, int end)
    {
        while (start < end && s[start] == s[end])
        {
            ++start;
            --end;
        }
        return start >= end;
    }
};