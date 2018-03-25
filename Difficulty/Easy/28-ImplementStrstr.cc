class Solution
{
  public:
    int strStr(string haystack, string needle)
    {
        // 边界条件
        // 法一：暴力匹配
        if (needle.empty())
            return 0; // 不合法参数错误返回0
        // 从haystack[0]开始匹配一直到haystack[N-1]开始匹配，共N种匹配模式，依次枚举检查
        const int N = haystack.size() - needle.size() + 1;
        for (int i = 0; i < N; i++)
        {
            int j = i;
            int k = 0;
            while (j < haystack.size() && k < needle.size() && haystack[j] == needle[k])
            {
                // 匹配
                j++;
                k++;
            }
            if (k == needle.size())
                return i;
        }
        return -1; // 没有一个匹配的，返回-1
    }

    // 法二：KMP算法
    // 计算部分匹配表，即next数组
    void compute_prefix(string pattern, int next[])
    {
        int i;
        int j = -1;
        const int m = pattern.size();

        next[0] = j;
        for (i = 1; i < m; ++i)
        {
            while (j > -1 && pattern[j + 1] != pattern[i])
                j = next[j];
            if (pattern[i] == pattern[j + 1])
                j++;
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle)
    {
        int i;
        int j = -1;
        const int n = haystack.size();
        const int m = needle.size();
        if (n == 0 && m == 0)
            return 0;
        if (m == 0)
            return 0;
        int *next = (int *)malloc(sizeof(int) * m); // malloc返回的是void*，需要强制转换成具体类型的指针

        compute_prefix(needle, next);

        for (i = 0; i < n; i++)
        {
            while (j > -1 && needle[j + 1] != haystack[i])
                j = next[j];
            if (haystack[i] == needle[j + 1])
                j++;
            if (j == m - 1)
            {
                free(next);
                return i - j;
            }
        }
        free(next);
        return -1;
    }
};