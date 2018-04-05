/* 
    基本方法：每次取n的当前低位判断是否为1，计数之
 */
class Solution
{
  public:
    int hammingWeight(uint32_t n)
    {
        int count = 32;
        int result = 0;
        int curBit = 0;
        while (count-- > 0)
        {
            curBit = n & 1;
            if (curBit == 1)
                result++;
            n = n >> 1;
        }
        return result;
    }
};

/* 
    巧妙方法：n & (n-1) 可将n的最后一个bit 1(从右往左的第一个1)消去，用while判断是否已经消去所有的1
 */
class Solution
{
  public:
    int hammingWeight(uint32_t n)
    {
        int result = 0;
        while (n != 0)
        {
            result++;
            n = n & (n - 1);
        }
        return result;
    }
};