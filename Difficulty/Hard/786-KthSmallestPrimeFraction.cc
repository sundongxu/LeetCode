// 二分查找
class Solution
{
  public:
    vector<int> kthSmallestPrimeFraction(vector<int> &A, int K)
    {
        const int n = A.size();
        double l = 0;
        double r = 1.0;
        while (l < r)
        {
            double m = (l + r) / 2;
            double max_f = 0.0;
            int total = 0;
            int p, q = 0;
            for (int i = 0, j = 1; i < n - 1; ++i)
            {
                while (j < n && A[i] > m * A[j])
                    ++j;
                if (n == j)
                    break;
                total += (n - j);
                const double f = static_cast<double>(A[i]) / A[j];
                if (f > max_f)
                {
                    p = i;
                    q = j;
                    max_f = f;
                }
            }
            if (total == K)
                return {A[p], A[q]};
            else if (total > K)
                r = m;
            else
                l = m;
        }
        return {};
    }
};