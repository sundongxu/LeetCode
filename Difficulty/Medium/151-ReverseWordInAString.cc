class Solution
{
  public:
    // 反转字符串i到j位，都是闭区间
    void reverseWord(string &s, int i, int j)
    {
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    void reverseWords(string &s)
    {
        int i = 0, j = 0;
        int l = 0;
        int len = s.size();
        int wordcount = 0;

        while (1)
        {
            // 一轮循环完成一个单词的反转
            while (i < len && s[i] == ' ')
                i++; // 跳过单词开头的空格
            if (i == len)
                break;
            if (wordcount)
                s[j++] = ' ';
            l = j;
            while (i < len && s[i] != ' ')
                s[j++] = s[i++];
            reverseWord(s, l, j - 1); // 就地反转当前单词，左边界l，右边界j-1
            wordcount++;
        }

        s.resize(j);
        reverseWord(s, 0, j - 1); // 最后反转整个字符串
    }
};