/* 
    递归会超时，但可用于帮助理解题意
    时间复杂度O(n!*m!)，空间复杂度O(n)，ｎ和m分别为s和p的长度
 */
#include <iostream>
#include <string>

using namespace std;

class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        return isMatch(s.c_str(), p.c_str());
    }

    //   private:
    bool isMatch(const char *s, const char *p)
    {
        if (*p == '*')
        {
            while (*p == '*') // 跳过连续'*'
                p++;
            if (*p == '\0') // 即p仅含'*'，而'*'可匹配任意序列，当然true
                return true;
            while (*s != '\0' && !isMatch(s, p))
                // 如s当前字符不是结束符，且s当前与p不匹配
                // 于是p就用'*'去匹配，后移s直至两者可以匹配或s到了结束符
                s++;
            return *s != '\0';
            // 若*s == '\0'，即s结束了，循环终止，看似好像匹配成功了，但是这里p还有剩余字符！
            // 若*s != '\0'，即s未结束，循环终止是因为isMatch(s,p)=true，即s与p匹配完成
        }
        else if (*p == '\0' || *s == '\0')
            return *p == *s;
        else if (*p == *s || *p == '?') // p与s对应字符能够匹配
            return isMatch(++s, ++p);
        else // 对应字符不能匹配且p也不是'?'和'*'
            return false;
    }
};

/* 
    递归超时，那就迭代，AC
    时间复杂度O(n*m)，空间复杂度O(1)
 */

class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        return isMatch(s.c_str(), p.c_str());
    }

    bool isMatch(const char *s, const char *p)
    {
        bool star = false;
        const char *str, *ptr;
        for (str = s, ptr = p; *str != '\0'; str++, ptr++)
        {
            switch (*ptr)
            {
            case '?':
                break;
            case '*':
                star = true;
                s = str;
                p = ptr;
                while (*p == '*') // 跳过p中连续'*'
                    p++;
                if (*p == '\0') // p指向结束符，表示p已经匹配成功
                    return true;
                str = s - 1; // 因为for循环会自增str
                ptr = p - 1; // 因为for循环会自增ptr，ptr移动至连续'*'之后第一个不是'*'的字符
                break;
            default:
                if (*str != *ptr)
                {
                    if (!star) // 如果p前面没有'*'，且s与p当前对应位置不匹配
                        return false;
                    s++; // p有'*'，s后移从下一个位置开始与p当前位匹配
                    str = s - 1;
                    ptr = p - 1;
                }
                break;
            }
        }
        while (*ptr == '*') // str已经结束，ptr若还是'*'，则可令其匹配空串
            ptr++;
        return *ptr == '\0'; // str结束了，ptr也要结束才匹配成功
    }
};

int main()
{
    cout << Solution().isMatch("aa", "a") << endl;
    cout << Solution().isMatch("aa", "aa") << endl;
    cout << Solution().isMatch("aaa", "aa") << endl;
    cout << Solution().isMatch("aa", "*") << endl;
    cout << Solution().isMatch("aa", "a*") << endl;
    cout << Solution().isMatch("ab", "?*") << endl;
    cout << Solution().isMatch("aab", "c*a*b") << endl;

    // 以下两个测试用例特别关注
    // 最后s指向’a‘，而p也指向'a'，两者成功匹配，返回true
    cout << Solution().isMatch("ba", "*a") << endl;
    // 最后s指向'\0'，而p指向'a'，即未匹配完p，s就结束了，故匹配失败，返回false
    cout << Solution().isMatch("bb", "*a") << endl;

    return 0;
}