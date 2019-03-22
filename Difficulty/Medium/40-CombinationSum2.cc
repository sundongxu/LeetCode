#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ret;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(ret, path, candidates, target, 0);
        return ret;
    }

    void dfs(vector<vector<int>> &result, vector<int> &path, vector<int> &candidates, int gap, int start)
    {
        if (gap == 0)
        {
            result.push_back(vector<int>(path));
            return;
        }

        int prev = -1;
        for (int i = start; i < candidates.size(); ++i)
        {
            if (prev == candidates[i])
                continue;
            prev = candidates[i];
            if (gap < candidates[i])
                return;
            path.push_back(candidates[i]);
            dfs(result, path, candidates, gap - candidates[i], i + 1);  // 不取当前数的重复
            path.pop_back();
        }
    }
};