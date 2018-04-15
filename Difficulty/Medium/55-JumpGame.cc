// 法一：正向，从0出发，
// 在第i个位置总是跳nums[i]步，到达从当前位置所能到达的最远地方，即贪心
// 胆大的都贪心！(还是说反了...)
class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        int reach = 0; // 最右能够到达的位置，从0开始，终点是nums.size() - 1
        int end = nums.size() - 1;
        for (int i = 0; i <= reach && reach <= end; ++i)
            // i比reach小是必须的
            // reach每一步都是得到的当前所能到达的最远点，reach之前的点肯定可以到的
            reach = max(reach, i + nums[i]); // 之前能够到达reach
        return reach >= end;                 // 超过了也不要紧，reach以内的位置都是可以到达滴
        // 总是记住reach是最远能够到达的位置！！！
    }
};

// 法二：逆向，从目标位置即最后一个位置往回跳，看能不能回到第0个位置
class Solution
{
  public:
    bool canJump(const vector<int> &nums)
    {
        if (nums.empty())
            return true;
        // 逆向回跳，最左能到达哪里
        int left_most = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; --i)
            // 回跳时遍历之前的每一个位置
            if (i + nums[i] >= left_most)
                left_most = i;
        return left_most == 0;
    }
};

// 法三：动规，时间复杂度O(n)，空间复杂度O(n)
// 状态为f[i]，表示从第0层出发，走到nums[i]时剩余的最大步数
// 状态转移方程为：f[i] = max(f[i-1], nums[i-1]) - 1, i > 0
class Solution
{
  public:
    bool canJump(const vector<int> &nums)
    {
        vector<int> f(nums.size, 0);
        f[0] = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            f[i] = max(f[i - 1], nums[i - 1]) - 1;
            if (f[i] < 0)
                return false;
        }
        return f[nums.size() - 1] >= 0;
    }
};