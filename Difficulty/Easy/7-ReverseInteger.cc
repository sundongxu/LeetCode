class Solution
{
  public:
    int reverse(int x)
    {
        long long r = 0; // 可能int溢出(超过2^32=2147483647正溢出，或小于2147483648)，用long long存
        long long t = x;
        t = t > 0 ? t : -t; // 全做正数处理
        for (; t; t /= 10)
            r = r * 10 + t % 10;
        bool isN = x > 0 ? false : true;               // 是否为负
        if (r > 2147483647 || (isN && r > 2147483648)) // 是负数且小于-2147483648
            return 0;
        else
        {
            if (isN)
                return -r;
            else
                return r;
        }
    }
};