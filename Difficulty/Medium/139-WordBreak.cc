// 动态规划
// 设状态为f(i)，表示s[0,i]是否可以分词
// 时间复杂度为O(n^2)，空间复杂度为O(n)
class Solution
{
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // 长度为n的字符串有n+1个隔板
        vector<bool> f(s.size() + 1, false);
        f[0] = true; // 空字符串
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (f[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())
                {
                    // 将s[0,i]，长度为i+1，分为两个子部分：s[0,j]，长度为j+1，和s[j+1,i]，长度为i-j
                    // (j+1) + (i-j) = i+1
                    f[i] = true;
                    break;
                }
            }
        }
        return f[s.size()];
    }
};