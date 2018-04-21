/* 
    递归和迭代两兄弟形影不离
 */

// 先递归
// 增量构造法，深搜，时间复杂度O(n^2)，空间复杂度O(n)
// 每个元素两种选择，选或不选
class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &S)
    {
        sort(S.begin(), S.end()); // 输出有序
        vector<vector<int>> result;
        vector<int> path;
        subsets(S, path, 0, result);
        return result;
    }

  private:
    static void subsets(const vector<int> &S, vector<int> &path, int step,
                        vector<vector<int>> &result)
    {
        if (step == S.size())
        {
            result.push_back(path);
            return;
        }
        // ̼不选 S[step]
        subsets(S, path, step + 1, result);
        // 选 S[step]
        path.push_back(S[step]);
        subsets(S, path, step + 1, result);
        path.pop_back();
    }
};

// 位向量法，深搜，时间复杂度O(n^2)，空间复杂度O(n)
// 开一个位向量 bool selected[n]，每个元素可以选或不选
class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &S)
    {
        sort(S.begin(), S.end()); // 输出有序
        vector<vector<int>> result;
        vector<bool> selected(S.size(), false);
        subsets(S, selected, 0, result);
        return result;
    }

  private:
    static void subsets(const vector<int> &S, vector<bool> &selected, int step,
                        vector<vector<int>> &result)
    {
        if (step == S.size())
        {
            vector<int> subset;
            for (int i = 0; i < S.size(); i++)
            {
                if (selected[i])
                    subset.push_back(S[i]);
            }
            result.push_back(subset);
            return;
        }
        // ̼不选 S[step]
        selected[step] = false;
        subsets(S, selected, step + 1, result);
        // 选 S[step]
        selected[step] = true;
        subsets(S, selected, step + 1, result);
    }
};

// 再迭代
// 依然增量构造法，时间复杂度O(n^2)，空间复杂度O(n)
class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &S)
    {
        sort(S.begin(), S.end());
        vector<vector<int>> result(1); // 初始化有一个空的vector:[]
        for (auto elem : S)
        {
            result.reserve(result.size() * 2); // 增加capacity不改变size
            auto half = result.begin() + result.size();
            copy(result.begin(), half, back_inserter(result));
            for_each(half, result.end(), [&elem](decltype(result[0]) &e) {
                e.push_back(elem);
            });
        }
        return result;
    }
};

// 二进制法
// 本方法的前提是：集合的元素不超过int位数
// 用一个int整数表示位向量，第i位为1，则表示选择S[i]，为0则表示不选择
// 例如S={A,B,C,D}，则0110=6表示子集{B,C}
class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &S)
    {
        sort(S.begin(), S.end());
        vector<vector<int>> result;
        const size_t n = S.size();
        vector<int> v;
        for (size_t i = 0; i < 1 << n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (i & 1 << j)
                    v.push_back(S[j]);
            }
            result.push_back(v);
            v.clear();
        }
        return result;
    }
};