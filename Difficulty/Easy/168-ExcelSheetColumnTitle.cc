class Solution
{
  public:
    string convertToTitle(int n)
    {
        // 我的版本... 和版本二比起来... 好啰嗦...
        map<int, char> dict;
        int r = 0;
        for (int i = 0; i <= 25; i++)
            dict[i] = 'A' + i;
        string result = "";
        while (n != 0)
        {
            r = (n - 1) % 26;
            result += dict[r];
            n = (n - 1) / 26;
        }

        // for (; n != 0; r = (n - 1) % 26, n = (n - 1) / 26) // 不能这么写，逗号表达式前后两个不知道先算谁！！！
        //     result += dict[r];

        reverse(result.begin(), result.end());
        return result;

        // 一行答案...厉害了！
        // 时刻边界条件判断：n==0
        // return n == 0 ? "" : convertToTitle((n - 1) / 26) + (char) ((n - 1) % 26 + 'A');
    }
};