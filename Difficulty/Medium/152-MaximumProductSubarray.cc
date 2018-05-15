class Solution
{
  public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        // max product including the current num[i]
        int maxProduct = nums[0];

        // min product including the current num[i]
        int minProduct = nums[0];

        // global max product
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            int tmp = maxProduct;
            maxProduct = max(max(maxProduct * nums[i], nums[i]), minProduct * nums[i]);
            minProduct = min(min(minProduct * nums[i], nums[i]), tmp * nums[i]);

            result = max(result, maxProduct);
        }

        return result;
    }
};