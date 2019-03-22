class Solution
{
  public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        // 包含当前nums[i]的最大乘积
        int maxProduct = nums[0];

        // 包含当前nums[i]的最小乘积
        int minProduct = nums[0];

        int result = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            int tmp = maxProduct;
            maxProduct = max(max(maxProduct * nums[i], nums[i]), minProduct * nums[i]);
            minProduct = min(min(minProduct * nums[i], nums[i]), tmp * nums[i]);

            result = max(result, maxProduct); // 因为有时候可能minProduct是负数所以最小，后面如果乘个负数就有可能变成最大
        }

        return result;
    }
};