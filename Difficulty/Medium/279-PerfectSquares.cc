// DP
class Solution
{
  public:
    int numSquares(int n)
    {
        if (n <= 0)
            return 0;

        // cntPerfectSquares[i]定义为：使和为i的所需的最小完全平方数的个数
        vector<int> cntPerfectSquares(n + 1, INT_MAX);
        cntPerfectSquares[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            // 对于每个i，它都是一个完全平方数 j*j 和另一个数 i-j*j 之和
            for (int j = 1; j * j <= i; j++)
            {
                cntPerfectSquares[i] =
                    min(cntPerfectSquares[i], cntPerfectSquares[i - j * j] + 1);
            }
        }

        return cntPerfectSquares.back();
    }
};

// Static DP
class Solution
{
  public:
    int numSquares(int n)
    {
        if (n <= 0)
        {
            return 0;
        }

        // cntPerfectSquares[i] = the least number of perfect square numbers
        // which sum to i. Since cntPerfectSquares is a static vector, if
        // cntPerfectSquares.size() > n, we have already calculated the result
        // during previous function calls and we can just return the result now.
        static vector<int> cntPerfectSquares({0});

        // While cntPerfectSquares.size() <= n, we need to incrementally
        // calculate the next result until we get the result for n.
        while (cntPerfectSquares.size() <= n)
        {
            int m = cntPerfectSquares.size();
            int cntSquares = INT_MAX;
            for (int i = 1; i * i <= m; i++)
            {
                cntSquares = min(cntSquares, cntPerfectSquares[m - i * i] + 1);
            }

            cntPerfectSquares.push_back(cntSquares);
        }

        return cntPerfectSquares[n];
    }
};

class Solution
{
  private:
    int is_square(int n)
    {
        int sqrt_n = (int)(sqrt(n));
        return (sqrt_n * sqrt_n == n);
    }

  public:
    // Based on Lagrange's Four Square theorem, there
    // are only 4 possible results: 1, 2, 3, 4.
    int numSquares(int n)
    {
        // If n is a perfect square, return 1.
        if (is_square(n))
        {
            return 1;
        }

        // The result is 4 if and only if n can be written in the
        // form of 4^k*(8*m + 7). Please refer to
        // Legendre's three-square theorem.
        while ((n & 3) == 0) // n%4 == 0
        {
            n >>= 2;
        }
        if ((n & 7) == 7) // n%8 == 7
        {
            return 4;
        }

        // Check whether 2 is the result.
        int sqrt_n = (int)(sqrt(n));
        for (int i = 1; i <= sqrt_n; i++)
        {
            if (is_square(n - i * i))
            {
                return 2;
            }
        }

        return 3;
    }
};

class Solution
{
  public:
    int numSquares(int n)
    {
        while (n % 4 == 0)
            n /= 4;
        if (n % 8 == 7)
            return 4;
        for (int a = 0; a * a <= n; ++a)
        {
            int b = sqrt(n - pow(a, 2));
            if (a * a + b * b == n)
            {
                return !!a + !!b;
            }
        }
        return 3;
    }
};