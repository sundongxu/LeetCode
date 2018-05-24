class Solution
{
  public:
    string decodeString(const string &s, int &i)
    {
        string res;

        while (i < s.length() && s[i] != ']')
        {
            if (!isdigit(s[i]))
                res += s[i++];
            else
            {
                int n = 0;
                while (i < s.length() && isdigit(s[i]))  // 当前位为数字，表示后面括号括起字符串的重复次数
                    n = n * 10 + s[i++] - '0';

                i++; // 跳过'['
                string t = decodeString(s, i);  // 解码括号内部子串
                i++; // 跳过']'

                while (n-- > 0)  // 括号内部子串重复n次
                    res += t;
            }
        }

        return res;
    }

    string decodeString(string s)
    {
        int i = 0;
        return decodeString(s, i);
    }
};