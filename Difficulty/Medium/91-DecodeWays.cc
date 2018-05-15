#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int numDecodings(string s)
    {
        const int n = s.size();
        if (n == 0 || s[0] == '0')
            return 0;

        int prev = 0;
        int cur = 1;

        // 长度为n的字符串，有n+1个阶梯
        for (int i = 1; i < n; i++)
        {
            // 匹配到s[i]位置
            if (s[i - 1] == '0') // 如s[i-1]=0，则s[i]只能联合前一位进行解码，不能单独解码
                cur = 0;
            if (i < 2 || !(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
                prev = 0;

            int tmp = cur;
            cur = prev + cur;
            prev = tmp;
        }
        return cur;
    }
};

// 动态规划
class Solution
{
  public:
    int numDecodings(string s)
    {
        int dp[s.size() + 1];
        if (s == "0")
            return 0;
        if (s.size() == 1)
            return 1;
        dp[0] = 1;                          // dp[0]的意义是什么？
        dp[1] = (s[0] == '0') ? 0 : 1;      // 匹配s[0]
        for (int i = 2; i <= s.size(); i++) // 匹配s[i-1]
        {
            // 当前位s[i-1]加入解码
            // 两种解码方式：s[i-1]单独解码，与前一位s[i-2]联合解码
            //（1）单独解码：
            // ① 如当前位s[i-1]不为0，则可至少有一种解码方法：前面s[0]~s[i-2]之前已经解码过，有dp[i-1]种，而当前位s[i-1]可独立解码，只有一种解码方式
            // 故单独解码方法数为dp[i-1]
            // ② 如当前位s[i-1]为0，则当前位不可独立解码，而必须和前面一位即s[i-2]联合解码，即单独解码方法数为0
            dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];

            //（2）联合解码
            // 当前位s[i-1]与前一位s[i-2]联合解码过程：
            // ① 若前一位s[i-2]为1，若要联合解码，则当前位s[i-1]可为任意数值，前面s[0]~s[i-3]之前已经解码过，故联合解码方法数为dp[i-2]
            // ② 若前一位s[i-2]为2，若要联合解码，则当前位s[i-1]必须不超过6(即两位合起来最大26)，同样地，联合解码方法数为dp[i-2]
            // ③ 若前一位s[i-2]不为1、2，则不能联合解码，s[i-1]只能单独解码，联合解码方法数为0
            dp[i] += ((s[i - 2] == '1') || (s[i - 2] == '2' && s[i - 1] < '7')) ? dp[i - 2] : 0;

            // 解码至s[i-1]为止，总的解码方法数 = s[i-1]单独解码方法数 + s[i-1]与其前一位s[i-2]联合解码方法数
        }
        return dp[s.size()];
    }
};