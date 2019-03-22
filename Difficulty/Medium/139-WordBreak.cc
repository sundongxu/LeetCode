// 动态规划
// 设状态为f(i)，表示s[0,i)是否可以分词
// 时间复杂度为O(n^2)，空间复杂度为O(n)
class Solution
{
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // 长度为n的字符串有n+1个隔板
        const int n = s.size();
        vector<bool> f(n + 1, false);
        f[0] = true;                 // 空字符串
        for (int i = 1; i <= n; i++) // n个隔板放置位置
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (f[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) // s.substr(j, i - j)存在于词典中
                {
                    // 判断f[i]，对应s[0,i)，长度为i，分为两个子部分：s[0,j)，长度为j，和s[j,i)，长度为i-j
                    // j + (i-j) = i
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
};