#include <iostream>
#include <string>
using namespace std;

/* 
    题目要求：问给定字符串能否被某子串经多次拷贝构造得到
    特别注意，这里要求多次重复，一次是不行的，像"a"和"ab"这样的用例都会返回false
 */

// 一行版本
// 思想：将s全部重复一次构成新字符串，在新字符串中，s连续出现两次
// 再删去首尾两个字符，看看能否找到s
class Solution
{
  public:
    bool repeatedSubstringPattern(string s)
    {
        // cout << __func__ << endl;
        // string ss = s + s;
        // cout << ss << endl;
        // string subss = ss.substr(1, s.size() * 2 - 2);
        // cout << subss << endl;
        // size_t index = subss.find(s);
        // cout << "index = " << index << endl;
        return (s + s).substr(1, s.size() * 2 - 2).find(s) != string::npos;
    }
};

// 个人觉得最好理解的版本
// 循环，将string分成两个部分子串相加，第一部分从位置i到末尾，第二部分从位置0到i
// 然后第二部分追加到第一部分后面，看是否等于原字符串s，若相等，则返回true
// 注意循环不能包括首尾两个字符的位置
class Solution
{
  public:
    bool repeatedSubstringPattern(string s)
    {
        string nextStr = s;
        int len = s.size();
        if (len <= 1)
            return false;
        for (int i = 1; i <= len / 2; i++)
        {
            if (len % i == 0)
            {
                nextStr = leftShift(s, i);
                if (nextStr == s)
                    return true;
            }
        }
        return false;
    }

    string leftShift(string &str, int l)
    {
        string ret = str.substr(l);
        ret += str.substr(0, l);
        return ret;
    }
};

class Solution
{
    bool repeatedSubstringPattern(string str)
    {
        int n = str.length();
        for (int i = 1; i <= n / 2; i++)
            if (n % i == 0 && str.substr(i) == str.substr(0, n - i))
                return true;
        return false;
    }
};

class Solution
{
    //   public:
    //     bool repeatedSubstringPattern(string str)
    //     {
    //         int i = 1, j = 0, n = str.size();
    //         vector<int> dp(n + 1, 0);
    //         while (i < str.size())
    //         {
    //             if (str[i] == str[j])
    //                 dp[++i] = ++j;
    //             else if (j == 0)
    //                 i++;
    //             else
    //                 j = dp[j];
    //         }
    //         return dp[n] && dp[n] % (n - dp[n]) == 0;
    //     }

  public:
    bool repeatedSubstringPattern(string str)
    {
        int k = -1, m = str.size(), pi[m + 1] = {-1};
        for (int i = 1; i <= m; i++)
        {
            while (k >= 0 && str[k] != str[i - 1])
                k = pi[k];
            pi[i] = ++k;
        }
        return pi[m] && (pi[m] % (m - pi[m]) == 0);
    }
};

int main()
{
    cout << "result(0/1):" << Solution().repeatedSubstringPattern("a") << endl;
    cout << "result(0/1):" << Solution().repeatedSubstringPattern("ab") << endl;
    cout << "result(0/1):" << Solution().repeatedSubstringPattern("abab") << endl;
    cout << "result(0/1):" << Solution().repeatedSubstringPattern("abcabcabc") << endl;

    return 0;
}