class Solution
{
  public:
    int getSum(int a, int b)
    {
        int sum = a;

        while (b != 0)
        {
            sum = a ^ b;      // 计算没有进位的情况下的a与b的和
            b = (a & b) << 1; // 计算进位，如没有进位，即b=0，说明上一步的sum即最终结果，循环应该结束
            a = sum;          // 计算没有进位的和与进位之和的结果
        }

        return sum;
    }
};