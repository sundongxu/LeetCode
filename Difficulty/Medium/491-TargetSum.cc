// 所有的数必须都用上
// DP 或 DFS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
  public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int countWays = 0;
        dfs(nums, S, 0, countWays);
        return countWays;
    }

    void dfs(vector<int> &nums, int leftSum, int cur, int &countWays)
    {
        if (cur == nums.size() - 1)
        {
            if (leftSum == nums[cur])
                countWays++;

            if (leftSum == -nums[cur]) // 最后一个元素取正负两种情况
                countWays++;
            return;
        }

        dfs(nums, leftSum - nums[cur], cur + 1, countWays); // '+'
        dfs(nums, leftSum + nums[cur], cur + 1, countWays); // '-'
    }
};

int main()
{

    // vector<int> nums = {1, 1, 1, 1, 1};
    // int S = 3;

    vector<int> nums = {1, 0};
    int S = 1;

    // vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 1};
    // int S = 1;

    Solution s;
    cout << s.findTargetSumWays(nums, S) << endl;
    return 0;
}