/* 
    实际就是考的std::next_permutation()这个标准库函数
 */
class Solution
{
  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        do
        {
            result.push_back(nums); // 自身就是一个排列可能，先执行一次
        } while (next_permutation(nums.begin(), nums.end()));

        return result;
    }
};

// 自行实现next_permutation()
// 直接调用31题的nextPermutation()
class Solution
{
  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        do
        {
            result.push_back(nums); // 自身就是一个排列可能，先执行一次
        } while (nextPermutation(nums.begin(), nums.end()));

        return result;
    }

    template <typename BidiIt>
    bool nextPermutation(BidiIt first, BidiIt last)
    {
        // Get a reversed range to simplify reversed traversal.
        const auto rfirst = reverse_iterator<BidiIt>(last);
        const auto rlast = reverse_iterator<BidiIt>(first);
        // Begin from the second last element to the first element.
        auto pivot = next(rfirst);
        // Find `pivot`, which is the first element that is no less than its
        // successor. `Prev` is used since `pivort` is a `reversed_iterator`.
        while (pivot != rlast && *pivot >= *prev(pivot))
            ++pivot;
        // No such elemenet found, current sequence is already the largest
        // permutation, then rearrange to the first permutation and return false.
        if (pivot == rlast)
        {
            reverse(rfirst, rlast);
            return false;
        }
        // Scan from right to left, find the first element that is greater than
        // `pivot`.
        auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
        swap(*change, *pivot);
        reverse(rfirst, pivot);
        return true;
    }
};

// 递归
// 深搜，增量构造法
// 时间复杂度O(n!)，空间复杂度O(n)
class Solution
{
  public:
    vector<vector<int>> permute(vector<int> &num)
    {
        sort(num.begin(), num.end());
        vector<vector<int>> result;
        vector<int> path; // 中间结果
        dfs(num, path, result);
        return result;
    }

  private:
    void dfs(const vector<int> &num, vector<int> &path,
             vector<vector<int>> &result)
    {
        if (path.size() == num.size()) // 收敛条件，本次排列构造完成
        {
            result.push_back(path);
            return;
        }
        // 扩展状态
        for (auto i : num)
        {
            // 查找i是否在path中出现过
            auto pos = find(path.begin(), path.end(), i); // 未出现则 == path.end()
            if (pos == path.end())
            {
                path.push_back(i);
                dfs(num, path, result);
                path.pop_back(); // 入栈又出栈
            }
        }
    }
};