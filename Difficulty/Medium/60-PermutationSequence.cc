/* 
    暴力法：直接求出前k个排列，调用了k-1次next_permutation()
    求出了前k个排列，但是比较浪费，因为只需要第k个排列
    利用康托编码的思路：假设有n个不重复的元素，第k个排列是a1,a2,a3,...,an
    那么a1是哪个数呢？
    把a1去掉，那么剩下的排列为a2,a3,...,an，共计n-1个元素，就有(n-1)!个排列，于是就可以知道a1=k/(n-1)!
 */
class Solution
{
  public:
    string getPermutation(int n, int k)
    {
        string s(n, '0');
        string result;
        for (int i = 0; i < n; ++i) // s = "123...n"
            s[i] += i + 1;
        return kth_permutation(s, k);
    }

  private:
    int factorial(int n)
    {
        int result = 1;
        for (int i = 1; i <= n; ++i)
            result *= i;
        return result;
    }
    // seq已排好序，是第一个排列
    template <typename Sequence>
    Sequence kth_permutation(const Sequence &seq, int k)
    {
        const int n = seq.size();
        Sequence S(seq);
        Sequence result;
        int base = factorial(n - 1);
        --k; // 康托编码从0开始
        for (int i = n - 1; i > 0; k %= base, base /= i, --i)
        {
            auto a = next(S.begin(), k / base);
            result.push_back(*a);
            S.erase(a);
        }
        result.push_back(S[0]); // 最后一个
        return result;
    }
};