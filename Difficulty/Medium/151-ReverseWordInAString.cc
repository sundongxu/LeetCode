class Solution
{
  public:
    // function to reverse any part of string from i to j (just one word or entire string)
    void reverseword(string &s, int i, int j)
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
            while (i < len && s[i] == ' ')
                i++; // 跳过单词开头的空格
            if (i == len)
                break;
            if (wordcount)
                s[j++] = ' ';
            l = j;
            while (i < len && s[i] != ' ')
            {
                s[j] = s[i];
                j++;
                i++;
            }
            reverseword(s, l, j - 1); // reverse word in place
            wordcount++;
        }

        s.resize(j);              // resize result string
        reverseword(s, 0, j - 1); // reverse whole string
    }
};