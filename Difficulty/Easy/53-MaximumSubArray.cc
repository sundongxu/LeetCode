#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 动态规划
class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        int result = INT_MIN, f = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            f = max(f + nums[i], nums[i]);
            result = max(result, f);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(nums) << endl;
}