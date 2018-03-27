// My Version，Recursion
class Solution
{
  public:
    string countAndSay(int n)
    {
        // 边界条件处理
        if (n == 1)
            return "1";
        //递归调用，然后对字符串处理
        string str = countAndSay(n - 1) + "*"; //为了str末尾的标记，方便循环读数
        int count = 1;
        string s = "";
        for (int i = 0; i < str.size() - 1; i++)
        {
            if (str[i] == str[i + 1])
                count++; //计数增加
            else
            {
                s = s + to_string(count) + str[i]; //上面的*标记这里方便统一处理
                count = 1;                         //初始化
            }
        }
        return s;
    }
};

// Fastest Version
class Solution
{
  public:
    void generate(string &s1, string &s2)
    {
        int i = 0;
        while (i < s1.size()) // 遍历前一个位置的string表示s1来得出当前位置的string表示s2
        {
            int j = i + 1;
            while (j < s1.size() && s1[j] == s1[i])
                j++;
            s2 += j - i + '0'; // '0'的目的： 1 + '0' = '1'
            s2 += s1[i];
            i = j; // 从第j个位置开始往后统计新序列表达
        }
    }

    string countAndSay(int n)
    {
        string s1 = "1"; // 记录第n-1个位置的字符串
        string s2 = "1"; // 记录第n个位置的字符串，即最终结果
        for (int i = 1; i < n; i++)
        {
            s2 = "";
            generate(s1, s2); // 用前一个位置的string表示来生成当前位置的string表示
            s1 = s2;
        }
        return s2; // s2是结果
    }
};