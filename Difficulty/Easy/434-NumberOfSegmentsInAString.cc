/* 
    segment之间由空格分隔，那么遍历此string
    遇到每个segment的开始字符时，计数器加1
    而开始字符可按如下判定：若当前字符不是空格，且前一个字符为空格
    那么当前字符就是一个新segment的第一个字符
 */
class Solution
{
  public:
    int countSegments(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
            if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ')
                count++;
        return count;
    }
};