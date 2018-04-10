/* 
    问题：要求找出最长的回文子串
 */

// 法一：暴力枚举法，复杂度O(n^3)
// 分析超时原因：
// 以任意两个位置作为起点和终点(不包括自身一个字符为回文串的情况)，分别验证它们标识的子串是否为回文串
// 起点与终点的组合共有n*(n-1)/2种，复杂度为O(n^2)，而验证每个子串是否为回文串也是一个复杂度O(n)的任务
// 嵌套在一起，故而暴力法复杂度为O(n^3)，一定超时

// 法二：记忆化搜索，即备忘录法，复杂度O(n^2)，设f[i][j]表示[i,j]之间的最长回文子串
// 递推方程如下：
// if (i == j)，f[i][j] = s[i]
// if (s[i] == s[j] && f[i+1][j-1] == s[i+1][j-1])，f[i][j] = s[i][j]
// else f[i][j] = max(f[i+1][j-1], f[i][j-1], f[i+1][j])

// 法三：动态规划，复杂度O(n^2)，设状态为f(i,j)，表示区间[i,j]是否为回文串
// if 子串　ｓ[i],...,s[j] 为一个回文串，则f(i,j) = true
// else f(i,j) = false
// 而已知：f(i,i) = true，和f(i,i+1) = (s[i] == s[i+1])
// 则状态转移方程如下：
// f(i,j) = true，条件为i=j，或(s[i]==s[j] && i-j<2)，或(s[i]==s[j] && f(i+1, j-1))
// 不满足上述条件则f(i,j) = false
class Solution
{
  public:
    string longestPalindrome(string s)
    {
        if (s.size() == 0 || s.size() == 1)
            return s;
        const int n = s.size();
        bool f[n][n];
        fill_n(&f[0][0], n * n, false); // 第一个参数不能用f，二维数组元素在内存中连续存储
        // 用vector会超时
        // vector<vector<bool>> f(n, vector<bool>(n, false));
        size_t max_len = 1, start = 0; // 最长回文串的长度、起点
        for (size_t i = 0; i < n; i++)
        {
            f[i][i] = true;
            for (size_t j = 0; j < i; j++) // 为什么j只能从i的左边开始，而不是右边呢？
            {
                // 这个判断条件很关键了
                // 位置j在i之前，如果两者对应字符相等
                // 那么，如果两者相差小于2，则说明j到i一定为回文子串，故f[j][i] = true
                // 如相差大于2，则还要判断j+1到i-1是否为回文子串，即上一个状态f[j+1][i-1]是否为true，若是，则f[j][i] = true
                f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j + 1][i - 1]));
                if (f[j][i] && max_len < (i - j + 1))
                {
                    max_len = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, max_len);
    }
};

// 法四：围绕中心扩展
// 包含2n-1个可能中心点，这是因为两个字符之间的区域也可以作为回文串的中心，这样的回文串有偶数个字符
class Solution
{
  public:
    string longestPalindrome(string s)
    {
        if (s.size() == 0 || s.size() == 1)
            return s;
        int start = 0, end = 0;
        // 两层循环，复杂度O(n^2)
        for (int i = 0; i < s.size(); i++)
        {
            int len1 = expandAroundCenter(s, i, i);     // 以第i个元素为中心向两边出发
            int len2 = expandAroundCenter(s, i, i + 1); // 以第i个元素与第i+1个元素的中间位置向两边出发
            int len = max(len1, len2);
            if (len > end - start + 1)
            {
                start = i - (len - 1) / 2; // 当前最长回文子串的起点
                end = i + len / 2;         // 当前最长回文子串的终点
            }
        }
        return s.substr(start, end - start + 1);
    }

  private:
    int expandAroundCenter(string s, int left, int right)
    {
        int L = left, R = right;
        while (L >= 0 && R < s.size() && s[L] == s[R])
        {
            L--;
            R++;
        }
        return R - L - 1;
    }
};

// 法五：Manacher's Algorithm，复杂度O(n)
// 择日再战...