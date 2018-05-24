// 要求时间复杂度O(n)，空间复杂度也为O(n)
class Solution
{
  public:
    vector<int> countBits(int num)
    {
        vector<int> ret(num + 1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i & (i - 1)] + 1; // i & (i-1) 可用于把i的二进制表示中的最右边(低位)的1消去
        return ret;
    }
};