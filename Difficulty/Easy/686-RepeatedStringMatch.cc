/* 
    题目要求：问A要重复多少次以后才能使B成为A的一个子串
    分析：首先A重复若干次后至少要保证由连续的若干个A构成的新字符串的长度 <= B的长度
    想象一下：S=A+A+A+...+A，如果B是S的一个子串，我们仅仅只需要去检查：
    S[0:]，S[1:]，...，S[len(A) - 1]是不是以B开头，如果是以B开头是不是之中包含完整的B
    此时S肯定的足够长的，即比B大，并且S的周期是A，再从S[len(A)]及之后的位置判断它们是不是以B开头
    和前面的结果是一样的(S的周期性决定的)
    所以A的重复次数首先要保证重复后的新字符串刚好比B长，此时再多加一个A，就能保证：
    S[0:]，S[1:]，...，S[len(A) - 1] 都可以有足够的空间包含B
 */
class Solution
{
  public:
    int repeatedStringMatch(string A, string B)
    {
        int least_times = 1;
        string A_copies = A;
        while (A_copies.size() < B.size())
        {
            least_times++;
            A_copies += A;
        }

        if (A_copies.find(B) != string::npos)
            return least_times;
        if ((A_copies += A).find(B) != string::npos)
            return least_times + 1;
        return -1;
    }
};

// 分析参见：https://leetcode.com/problems/repeated-string-match/discuss/108118/C++Java-Clean-Code
class Solution
{
  public:
    int repeatedStringMatch(string a, string b)
    {
        string as = a;
        for (int rep = 1; rep <= b.length() / a.length() + 2; rep++, as += a)
            if (as.find(b) != string::npos)
                return rep;
        return -1;
    }
};

// KMP
class Solution
{
  public:
    int repeatedStringMatch(string a, string b)
    {
        vector<int> kmp(b.size() + 1);
        for (int i = 1, j = 0; i < b.size();)
        {

            //printf("j%c, i%c\n",b[j],b[i]);
            if (b[j] == b[i])
            {
                kmp[i++] = ++j;
            }
            else
            {
                if (j == 0)
                    i++;
                else
                    j = kmp[j - 1];
            }
        }

        // for (int i : kmp)
        // {
        // printf("%d", i);
        // }
        //printf("\n");
        for (auto i = 0, j = 0; i < a.size(); i++, j = kmp[j - 1])
        {

            while (j < b.size() && a[(i + j) % a.size()] == b[j])
            {
                // printf("match i%d j%d\n", i, j);
                ++j;
            }
            if (j == b.size())
                return ceil((float)(i + j) / a.size());
            else
                ;
            // printf("unmatch i%d j%d\n", i, j);
        }

        return -1;
    }
};