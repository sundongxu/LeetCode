// Fastest Version
int lengthOfLastWord(string s)
{
    int i = s.size() - 1;
    int length = 0;
    while (i >= 0 && s[i] == ' ')
        --i; // 退到最后一个不是空格的字符
    // 从最后一个字符的位置向前遍历，直到遇到下一个空格，表示最后一个单词已结束
    while (i >= 0 && s[i--] != ' ')
        ++length;
    return length;
}

// My Version
class Solution
{
  public:
    int lengthOfLastWord(string s)
    {
        if (s == "")
            return 0;
        int preLen = 0, curLen = 0;
        for (string::size_type i = 0; i < s.size(); i++)
        {
            preLen = curLen > 0 ? curLen : preLen;
            if (!isspace(s[i]))
                curLen++;
            else
                curLen = 0;
        }

        return curLen > 0 ? curLen : preLen;
    }
};

// STL
class Solution
{
  public:
    int lengthOfLastWord(string s)
    {
        auto first = find_if(s.rbegin(), s.rend(), ::isalpha); // 逆序搜索，找到最后一个是字符的位置
        auto last = find_if_not(first, s.rend(), ::isalpha);   // 从最后一个字符继续往前即逆序寻找直到第一个不是字符的位置
        // first指向最后一个字符，即最后一个单词的最后一个字符，last指向最后一个单词前的第一个空格
        // 两者距离即为最后一个单词的长度
        return distance(first, last); // 虽然按位置来说，last出现在first之前，但是这都是反向迭代器，求距离时要反过来
    }
};

// 顺序扫描
class Solution
{
  public:
    int lengthOfLastWord(string s)
    {
        return lengthOfLastWord(s.c_str());
    }

  private:
    int lengthOfLastWord(const char *s)
    {
        int len = 0;
        while (*s)
            if (*s++ != ' ')
                ++len;
            else if (*s && *s != ' ')
                len = 0;
        return len;
    }
};