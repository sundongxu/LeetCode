class Solution
{
  public:
    int reverse(int x)
    {
        long long result = 0; // 可能int溢出(超过2^32=2147483647正溢出，或小于2147483648)，用long long存
        long long origin = x;
        bool isN = x > 0 ? false : true;        // 是否为负
        origin = origin > 0 ? origin : -origin; // 全做正数处理
        for (; origin; origin /= 10)
            result = result * 10 + origin % 10;
        if (result > 2147483647 || (isN && result > 2147483648)) // 提前处理正负溢出
        // if (result > INT_MAX || (isN && result > -static_cast<long long>(INT_MIN))) // 提前处理正负溢出
            return 0;
        else
        {
            if (isN)
                return -result;
            else
                return result;
        }
    }
};