class Solution
{
  public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;
        vector<string> ip; // 存放中间结果
        dfs(s, ip, result, 0);
        return result;
    }

    void dfs(string &s, vector<string> &ip, vector<string> &result, int start)
    {
        // IP地址由4个IP子字符串组成
        if (ip.size() == 4 && start == s.size())
        {
            // 找到了一个合法解
            result.push_back(ip[0] + '.' + ip[1] + '.' + ip[2] + '.' + ip[3]);
            return;
        }

        // 还剩的位数过多，连每个IP子串都用掉3位字符都还有多
        if (s.size() - start > (4 - ip.size()) * 3)
            return; // 剪枝

        // 还剩的位数过少，连每个IP子串都只用1位字符都还不够
        if (s.size() - start < (4 - ip.size()))
            return; // 剪枝

        int num = 0;
        for (int i = start; i < start + 3; i++)  // 最多3位字符
        {
            num = num * 10 + (s[i] - '0');

            if (num < 0 || num > 255)
                continue; // 剪枝

            ip.push_back(s.substr(start, i - start + 1)); // s[i]包括在内
            dfs(s, ip, result, i + 1);                    // 从s[i+1]开始构造下一个IP子串
            ip.pop_back();

            // IP子串不允许前缀为0，但允许单个0
            if (num == 0)
                break;
        }
    }
};