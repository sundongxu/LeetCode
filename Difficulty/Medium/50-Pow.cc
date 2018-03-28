// 分而治之法

// 二分法？

// x^n = x^(n / 2) * x^(n / 2) * x^(n % 2)
// n为奇数，则 n = n / 2 + n / 2 + 1(n % 2 = 1)
// n为偶数，则 n = n / 2 + n / 2 + 0(n % 2 = 0)

class Solution
{
  public:
    double myPow(double x, int n)
    {
        if (n < 0)
            return 1.0 / power(x, -n);
        else
            return power(x, n);
    }

  private:
    double power(double x, int n)
    {
        // 递归时，最简单情形的结果应先写出
        if (n == 0)
            return 1;
        double v = power(x, n / 2);
        if (n & 0x1)
            return v * v * x;
        else
            return v * v;
    }
};