// 暴力枚举，复杂度O(n^2)
class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int sum = target;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (target == nums[i] + nums[j])
                    return vector<int>{i, j};
            }
        }
        return vector<int>{0, 0};
    }
};

// 哈希表，存储每个数对应的下标，复杂度O(n)
class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
            map[nums[i]] = i; // 用哈希表存储每个数对应下标
        for (int i = 0; i < nums.size(); i++)
        {
            const int gap = target - nums[i];
            if (map.find(gap) != map.end() && map[gap] > i)
            {
                result.push_back(i);
                result.push_back(map[gap]);
                break;
            }
        }
        return result;
    }
};