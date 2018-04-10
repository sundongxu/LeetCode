/* 
    左右括号要么嵌套，要么一对对分隔开
    一步步构造字符串，当左括号出现次数<n时，就可以放置新的左括号
    当右括号出现少于左括号时，就可以放置新的右括号
 */
class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string path;
        if (n > 0)
            generate(n, path, result, 0, 0);
        return result;
    }
    // l表示左括号出现的次数，r表示右括号出现的次数
    void generate(int n, string &path, vector<string> &result, int l, int r)
    {
        if (l == n)
        {
            // 左括号已经全部放置完
            // 此时应该在之后追加剩余右括号，个数为n-r
            string s(path);
            result.push_back(s.append(n - r, ')')); // 唯一更新result的地方
            return;
        }
        // 左括号没用完
        // 先试着再放一个左括号
        path.push_back('(');
        generate(n, path, result, l + 1, r); // result被更新
        path.pop_back();

        // 再试着放一个右括号
        if (l > r)
        {
            path.push_back(')');
            generate(n, path, result, l, r + 1); // result被更新
            path.pop_back();
        }
    }
};

class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        if (n == 0)
            return vector<string>(1, "");
        if (n == 1)
            return vector<string>(1, "()");
        vector<string> result;
        for (int i = 0; i < n; ++i)
            for (auto inner : generateParenthesis(i))
                for (auto outer : generateParenthesis(n - 1 - i))
                    result.push_back("(" + inner + ")" + outer);
        return result;
    }
};
