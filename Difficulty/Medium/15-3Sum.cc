/* 
    先排序，然后左右夹逼
    时间复杂度O(n^2)，空间复杂度O(1)
 */
class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        if (nums.size() < 3)
            return result;
        sort(nums.begin(), nums.end());

        const int target = 0;
        auto last = nums.end();
        for (auto i = nums.begin(); i < last - 2; ++i)  // i后面留两个位置：last-2和last-1
        {
            auto j = i + 1;
            if (i > nums.begin() && *i == *(i - 1))
                continue;
            auto k = last - 1;
            while (j < k)
            {
                if (*i + *j + *k < target)
                {
                    ++j;
                    while (*j == *(j - 1) && j < k)
                        ++j;
                }
                else if (*i + *j + *k > target)
                {
                    --k;
                    while (*k == *(k + 1) && j < k)
                        --k;
                }
                else
                {
                    result.push_back({*i, *j, *k});
                    ++j;
                    --k;
                    while (*j == *(j - 1) && *k == *(k + 1) && j < k)
                        ++j;
                }
            }
        }
        return result;
    }
};