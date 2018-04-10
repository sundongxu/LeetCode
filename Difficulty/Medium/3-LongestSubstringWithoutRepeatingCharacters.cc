/*
    问题：找出给定字符串中最长且不包含相同字符的子串，返回其长度
    假设子串里含有重复字符，则父串一定含有重复字符，单个子问题就可以决定父问题
    因此可用贪心法
    与动态规划不同，动规里，单个子问题只能影响父问题，不足以决定父问题
    思路：
    从左往右扫描，当遇到重复字母时，以上一个重复字母的index加1的位置作为新的搜索起始位置
    直到最后一个位置，复杂度O(n)
 */
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0 || s.size() == 1)
            return s.size();
        const int ASCII_MAX = 255;
        int last[ASCII_MAX];              // 记录字符上次出现过的位置，相当于字典了
        int start = 0;                    // 记录当前子串的起始位置
        fill(last, last + ASCII_MAX, -1); // 0也是有效位置，因此初始化为-1

        int max_len = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // 必须从0开始，因为循环体末尾要更新第0个字符最近出现的位置下标
            if (last[s[i]] >= start) // 初始化last元素都是-1
            // if满足时，s[i]已经至少出现过一次了，此时应该要更新max_len了
            {
                max_len = max(i - start, max_len);
                start = last[s[i]] + 1;
            }
            last[s[i]] = i; // 更新最近一次遇见字符s[i]的位置
        }
        // 如果某次搜索一直到字符串末尾都没有找到重复字符
        // 不能遗忘了最后一次更新max_len
        max_len = max((int)s.size() - start, max_len);
        return max_len;
    }
};