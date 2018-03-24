class Solution
{
  public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int d = 1;
        while (x / d >= 10)
            d *= 10;
        while (x > 0)
        {
            int q = x / d;  // 最高位
            int r = x % 10; // 最低位
            if (q != r)
                return false;
            x = x % d / 10; // 原数模除数d后去掉最高位，再除以10去掉最低位
            d /= 100;       // 原数减去2位之后，除数随之缩小10^2=100倍
        }
        return true;
    }
};