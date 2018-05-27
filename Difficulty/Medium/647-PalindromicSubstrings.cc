class Solution
{
  public:
    int countSubstrings(string s)
    {
        int N = s.size(), ans = 0;
        // N个字符，包括每个字符和相邻字符之间的位置在内，一共有2N-1个对称中心
        // 围绕对称中心向左右两边扩张，注意到如果[a,b]为回文子串，那么[a+1,b-1]一定也是
        for (int center = 0; center <= 2 * N - 1; ++center)
        {
            int left = center / 2;
            int right = left + center % 2;
            while (left >= 0 && right <= N - 1 && s[left] == s[right])
            {
                ans++;
                left--;
                right++;
            }
        }
        return ans;
    }
};