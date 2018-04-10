/* 
    测试用例中有一个开始没太看懂：isMatch("ab", ".*") → true
    的确是true，这表示"."可以出现0次或多次，而"."又可匹配任意单个字符，但没必要都匹配相同的字符
    一个匹配"a"，另一个匹配"b"是完全可以的，也就是说，".*"是可以匹配任意字符串的！
 */

// 先递归，AC
// 时间复杂度O(n)，空间复杂度O(1)
class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        return isMatch(s.c_str(), p.c_str());
    }

  private:
    bool isMatch(const char *s, const char *p)
    {
        if (*p == '\0') // 递归终止条件
            return *s == '\0';

        if (*(p + 1) != '*')
        {
            // s与p当前位置对应相等，或p为"."且s当前字符不为空，则进入下一个位置匹配
            if (*p == *s || (*p == '.' && *s != '\0'))
                return isMatch(s + 1, p + 1);
            else
                return false;
        }
        else // p的下一个字符为"*"
        {
            // p与s中对应字符匹配，或p为"."通配符
            // 则循环检查
            while (*p == *s || (*p == '.' && *s != '\0'))
            {
                if (isMatch(s, p + 2)) // 跳过p的下一个位置的"*"
                    return true;
                // 后移直至p与s对应不匹配，表示s出现连续相同字符
                // 而p通过两种方式连续匹配
                // （1）第一个位置字符对应相等，而p下一个字符为"*"，s中连续出现的相同字符得以匹配
                // （2）p第一个位置字符为"."，匹配任意单个字符，当然也匹配s第一个位置字符，此后s中连续出现该字符，同样可以被p匹配
                s++;
            } // 循环整个过程p都没有移动
            // 当前对应字符不匹配，但是p下一位为"*"，可以让该不匹配的字符在p中出现0次
            // 即可跳过p中与s当前位置不匹配的字符，p后移，s不变
            return isMatch(s, p + 2);
        }
    }
};

// 回溯 Tracebacking + 深度搜索 dfs, string版，AC
class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        if (p.size() == 0)
            return s.size() == 0;

        if (p.size() == 1 || p[1] != '*')
        {
            if (s.size() == 0 || (s[0] != p[0] && p[0] != '.'))
                return false;
            return isMatch(s.substr(1), p.substr(1));
        }
        else
        {
            int i = 0;
            while (p[0] == s[i] || p[0] == '.' && i < s.size())
            {
                if (isMatch(s.substr(i), p.substr(2)))
                    return true;
                i++;
            }
            return isMatch(s.substr(i), p.substr(2));
        }
    }
};

// 动规，自顶向下
// 设s长度为M，p长度为N，则时间和空间复杂度均为O(MN)
class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        const int len_s = s.size(), len_p = p.size();
        vector<vector<bool>> vec(len_s + 1, vector<bool>(len_p + 1, true));
        return dp(0, 0, s, p, vec);
    }

  private:
    bool dp(int i, int j, string ss, string pp, vector<vector<bool>> &vec)
    {
        bool ans;
        if (j == pp.size())
            ans = i == ss.size();
        else
        {
            bool first_match = (i < ss.size() && (pp[j] == ss[i] || pp[j] == '.'));
            if (j + 1 < pp.size() && pp[j + 1] == '*')
                ans = (dp(i, j + 2, ss, pp) || first_match && dp(i + 1, j, ss, pp));
            else
                ans = first_match && dp(i + 1, j + 1, ss, pp);
        }
        vec[i][j] = ans ? true : false;
        return ans;
    }
};

// 动规，自底向上
class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        const int len_s = s.size(), len_p = p.size();
        bool dp[len_s + 1][len_p + 1];
        for (int i = 0; i <= len_s; i++)
            for (int j = 0; j <= len_p; j++)
                dp[i][j] = false; // 局部数组要初始化，否则元素是未定义的值
        dp[len_s][len_p] = true;

        for (int i = len_s; i >= 0; i--)
        {
            for (int j = len_p - 1; j >= 0; j--)
            {
                bool first_match = (i < len_s && (p[j] == s[i] || p[j] == '.'));
                if (j + 1 < len_p && p[j + 1] == '*')
                    dp[i][j] = dp[i][j + 2] || first_match && dp[i + 1][j];
                else
                    dp[i][j] = first_match && dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
    }
};