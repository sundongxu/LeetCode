class Solution
{
  public:
    int countPrimes(int n)
    {
        vector<bool> check(n, true);
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (check[i])
                count++;
            for (int j = 2; i * j < n; j++)
                check[i * j] = false;
        }
        return count;
    }
};