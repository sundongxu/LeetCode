/* 
    先转换成小写transform
    两个纸质左右夹逼，对应字符(只判断数字和字母两种字符)不等时返回false
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