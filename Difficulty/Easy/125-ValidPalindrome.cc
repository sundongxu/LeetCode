/* 
    先转换成小写transform
    两个指针左右夹逼，对应字符(只判断数字和字母两种字符)不等时返回false
    空串返回true
    时间复杂度O(n)，空间复杂度O(1)
 */
class Solution
{
  public:
    bool isPalindrome(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        auto left = s.begin(), right = prev(s.end());
        while (left < right)
        {
            if (!::isalnum(*left))
                ++left;
            else if (!::isalnum(*right))
                --right;
            else if (*left != *right)
                return false;
            else
                left++, right--;
        }
        return true;
    }
};

class Solution
{
  public:
    bool isPalindrome(string s)
    {
        if(s.empty())
            return true;
        int l = 0, r = s.size() - 1;
        while(l < r)
        {
            if(!isalpha(s[l]) && !isdigit(s[l]))
            {
                l++;
                continue;
            }
            if(!isalpha(s[r]) && !isdigit(s[r]))
            {
                r++;
                continue;
            }
            if((s[l] | 0x20) != (s[r] | 0x20))  // 0x20是空格
                return false;
            l++;
            r--;
        }
        return true;
    }
};

// STL
class Solution
{
  public:
    static bool isspace(char c)
    {
        if(c == ' ') 
            return true;
        else if(c >= 'a' && c <= 'z')
            return false;
        else if(c >= '0' && c <= '9')
            return false;
        return true;
    }

    bool isPalindrome(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower());
        s.erase(remove_if(s.begin(), s.end(), isspace), s.end());
        string t = s;
        reverse(t.begin(), t.end());
        return t == s;
    }
};