// 先递归
// 增量构造，版本1
// 时间复杂度O(2^n)，空间复杂度O(1)
class Solution
{
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end()); // 必须排序
        vector<vector<int>> result;
        vector<int> path;
        dfs(nums, nums.begin(), path, result);
        return result;
    }

  private:
    static void dfs(const vector<int> &nums, vector<int>::iterator start,
                    vector<int> &path, vector<vector<int>> &result)
    {
        result.push_back(path);
        for (auto i = start; i < nums.end(); i++)
        {
            if (i != start && *i == *(i - 1))
                continue;
            path.push_back(*i);
            dfs(nums, i + 1, path, result);
            path.pop_back();
        }
    }
};

// 位向量法
// 时间复杂度O(2^n)，空间复杂度O(n)
class Solution
{
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        vector<int> count(nums.back() - nums.front() + 1, 0);
        // 计算所有元素的个数
        for (auto i : nums)
        {
            count[i - nums[0]]++;
        }
        // 每个元素选择了多少个
        vector<int> selected(nums.back() - nums.front() + 1, -1);
        subsets(nums, count, selected, 0, result);
        return result;
    }

  private:
    static void subsets(const vector<int> &nums, vector<int> &count,
                        vector<int> &selected, size_t step, vector<vector<int>> &result)
    {
        if (step == count.size())
        {
            vector<int> subset;
            for (size_t i = 0; i < selected.size(); i++)
            {
                for (int j = 0; j < selected[i]; j++)
                {
                    subset.push_back(i + nums[0]);
                }
            }
            result.push_back(subset);
            return;
        }
        for (int i = 0; i <= count[step]; i++)
        {
            selected[step] = i;
            subsets(nums, count, selected, step + 1, result);
        }
    }
};