// 不准用除法，O(n)时间复杂度，O(1)即常数空间

// O(n)空间
class Solution
{
  public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> fromBegin(n); // 前i个数字的乘积
        fromBegin[0] = 1;
        vector<int> fromLast(n); // 后i个数字的乘积
        fromLast[0] = 1;

        for (int i = 1; i < n; i++)
        {
            fromBegin[i] = fromBegin[i - 1] * nums[i - 1]; // nums[i-1]是正数第i个数字
            fromLast[i] = fromLast[i - 1] * nums[n - i];   // nums[n-i]是倒数第i个数字
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            // 除去num[i]的全部数的乘积即res[i]=frombegin[i]*fromlast[n-i-1]共计n-1个数字的乘积
            res[i] = fromBegin[i] * fromLast[n - 1 - i]; // frombegin[i]是前i个数字的乘积，fromLast是后n-1-i个数字的乘积
        }
        return res;
    }
};

// O(1)空间
class Solution
{
  public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        int fromBegin = 1;
        int fromLast = 1;
        vector<int> res(n, 1);

        for (int i = 0; i < n; i++)
        {
            res[i] *= fromBegin;
            fromBegin *= nums[i];
            res[n - 1 - i] *= fromLast;
            fromLast *= nums[n - 1 - i];
        }
        return res;
    }
};