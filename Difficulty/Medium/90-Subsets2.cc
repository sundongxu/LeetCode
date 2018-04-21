// 先递归
// 增量构造，版本1
// 时间复杂度O(2^n)，空间复杂度O(1)
class Solution
{
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &S)
    {
        sort(S.begin(), S.end()); // 必须排序
        vector<vector<int>> result;
        vector<int> path;
        dfs(S, S.begin(), path, result);
        return result;
    }

  private:
    static void dfs(const vector<int> &S, vector<int>::iterator start,
                    vector<int> &path, vector<vector<int>> &result)
    {
        result.push_back(path);
        for (auto i = start; i < S.end(); i++)
        {
            if (i != start && *i == *(i - 1))
                continue;
            path.push_back(*i);
            dfs(S, i + 1, path, result);
            path.pop_back();
        }
    }
};

// 位向量法
// 时间复杂度O(2^n)，空间复杂度O(n)
class Solution
{
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &S)
    {
        vector<vector<int>> result;
        sort(S.begin(), S.end());
        vector<int> count(S.back() - S.front() + 1, 0);
        // 计算所有元素的个数
        for (auto i : S)
        {
            count[i - S[0]]++;
        }
        // 每个元素选择了多少个
        vector<int> selected(S.back() - S.front() + 1, -1);
        subsets(S, count, selected, 0, result);
        return result;
    }

  private:
    static void subsets(const vector<int> &S, vector<int> &count,
                        vector<int> &selected, size_t step, vector<vector<int>> &result)
    {
        if (step == count.size())
        {
            vector<int> subset;
            for (size_t i = 0; i < selected.size(); i++)
            {
                for (int j = 0; j < selected[i]; j++)
                {
                    subset.push_back(i + S[0]);
                }
            }
            result.push_back(subset);
            return;
        }
        for (int i = 0; i <= count[step]; i++)
        {
            selected[step] = i;
            subsets(S, count, selected, step + 1, result);
        }
    }
};