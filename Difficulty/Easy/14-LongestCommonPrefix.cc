class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty()) // 一定处理边界条件！
            return "";
        for (int idx = 0; idx < strs[0].size(); ++idx) // 遍历第一个string的每个字符
            for (int i = 1; i < strs.size(); ++i)      // 遍历从第二个string开始每一个string
                if (strs[i][idx] != strs[0][idx])      // 比较第一个string与第i个string的对应位是否相等
                    return strs[0].substr(0, idx);     // 不包括idx所指位置的字符
        return strs[0];
    }
};