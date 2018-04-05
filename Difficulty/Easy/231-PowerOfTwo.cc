/* 
    暴力法会超时
 */
class Solution
{
  public:
    bool isPowerOfTwo(int n)
    {
        while (n % 2 == 0)
            n /= 2;
        if (n == 1)
            return true;
        else
            return false;
    }
};

/* 
    找规律：对于一个二进制表示的整数，2的整数次幂都是只有一个bit为1，其余都为0的
    同样可以用 n & (n-1) 去掉最后一个0，看看有几个bit 0
 */
class Solution
{
  public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0) // 边界条件，负数和0都不是2的整数幂
            return false;
        n = n & (n - 1); // 去掉n中的最后一个0
        if (n == 0)
            return true;
        else
            return false;
    }
};