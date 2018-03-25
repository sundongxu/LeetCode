/*
    本地难点在于分析str的输入用例，如何考虑全面：
    （1）丢弃前面出现的所有空格符" "，直到第一个不是空格的字符为止
    （2）从当前字符是否为‘+’和'-'，确定结果的正负，但是只需要一个+/-，连续出现两个，如++1，就是无效输入
    （3）从符号后面连续出现的全部数字都考虑进来，直到第一个不是数字的字符为止，如+31231da1s5d仍是有效输入，只是从d开始后面的字符全都要丢弃
    （4）如str中第一个非空格符不是符号或者数字，或者由于str为空或str全是空格字符，输入同样无效
    
    返回值，分如下几种情况：
    （1）无效输入用例，即无效转换，返回0
    （2）转换后的int值溢出，即为正数时>2147483647，为负数时<-2147483648，则返回INT_MAX(2147483647)或INT_MIN(-2147483648)


If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

*/

class Solution
{
  public:
    int myAtoi(string str)
    {
        int num = 0;
        int sign = 1;
        const int n = str.length();
        int i = 0;

        while (str[i] == ' ' && i < n)
            i++; // i为第一个不是空格的字符的下标

        if (str[i] == '+')
            i++;
        else if (str[i] == '-')
        {
            sign = -1;
            i++;
        } // i指向+/-号之后的第一个位置，即第一个有效数字

        for (; i < n; i++)
        {
            if (str[i] < '0' || str[i] > '9')
                break;
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
                return sign == -1 ? INT_MIN : INT_MAX;
            num = num * 10 + (str[i] - '0');
        }

        return num * sign;
    }
};