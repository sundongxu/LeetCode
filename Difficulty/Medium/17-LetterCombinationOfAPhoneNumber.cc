/* 
    注意0和1对应的字符串都是空串""
    递归 + 迭代
 */
// 递归，时间复杂度O(3^n)，空间复杂度O(n)
class Solution
{
  public:
    const vector<string> keyboard{
        "", "", "abc", // 0、 1 、2
        "def", "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        if (digits.empty())
            return result;
        dfs(digits, 0, "", result);
        return result;
    }

    void dfs(const string &digits, size_t cur, string path, vector<string> &result)
    {
        if (cur == digits.size()) // 递归终止条件
        {
            result.push_back(path);
            return;
        }
        for (auto c : keyboard[digits[cur] - '0'])
            dfs(digits, cur + 1, path + c, result);
    }
};

// 迭代，时间复杂度O(3^n)，空间复杂度O(1)
class Solution
{
  public:
    const vector<string> keyboard{
        " ", "", "abc", "def", // '0','1','2',...
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(const string &digits)
    {
        if (digits.empty())
            return vector<string>();
        vector<string> result(1, "");
        for (auto d : digits)
        {
            const size_t n = result.size();            // 当前数字之前的数字们构造的字母序列数目
            const size_t m = keyboard[d - '0'].size(); // 当前数字对应的字母数量
            result.resize(n * m);                      // result的最新大小，为之前的result大小乘上最新数字对应的字母数目

            for (size_t i = 0; i < m; ++i)
                copy(result.begin(), result.begin() + n, result.begin() + n * i);
            // 把之前的result的内容重复m次，连续存储
            // 之后再在这m个result内容上分别添加当前数字对应的m个字符
            for (size_t i = 0; i < m; ++i)
            {
                auto begin = result.begin();
                // for_each + lambda 表达式
                // 表示对在一对迭代器表示的范围内的元素(左闭右开)的引用(可直接修改该元素)
                // 分别调用lambda表达式
                for_each(begin + n * i, begin + n * (i + 1), [&](string &s) {
                    s += keyboard[d - '0'][i];
                });
            }
        }
        return result;
    }
};