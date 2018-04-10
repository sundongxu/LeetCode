/* 
    不能用乘、除和取模，那剩下的，还有加、减和位运算
    最简答的方法是不断减去被除数
    在这个基础上，可以做一点优化，每次把被除数翻倍，从而加速
    判断正负可用两者按位异或结果再右移31位，即看符号位的异或结果
    结果为0，则结果为正，result直接返回
    结果非0，则结果为负，result取反再返回
    int通常为4字节，用long long存储结果再转为int防止中间结果溢出
 */
class Solution
{
  public:
    int divide(int dividend, int divisor)
    {
        // 当dividend = INT_MIN时，-dividend会溢出，所以用long long
        // 当dividend = INT_MIN时，divisor=-1时，结果会溢出，所以用long long
        // 均转为正数，result计算结果也为正数，最后再判断符号
        long long a = dividend >= 0 ? dividend : -(long long)dividend;
        long long b = divisor >= 0 ? divisor : -(long long)divisor;
        long long result = 0;
        while (a >= b)
        {
            long long c = b;
            for (int i = 0; a >= c; ++i, c <<= 1)
            {
                a -= c;
                result += 1 << i;
            }
        }
        result = ((dividend ^ divisor) >> 31) ? (-result) : result;
        if (result > INT_MAX) // 正溢出，返回INT_MAX
            return INT_MAX;
        return result;
    }
};