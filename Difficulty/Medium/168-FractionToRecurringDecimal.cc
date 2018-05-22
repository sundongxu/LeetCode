class Solution
{
  public:
    string fractionToDecimal(int64_t n, int64_t d)
    {
        // 被除数为0
        if (n == 0)
            return "0";

        string res;

        // 决定符号，两者不同则为负，异或之
        if (n < 0 ^ d < 0)
            res += '-';

        // 操作数取绝对值做除法
        n = abs(n), d = abs(d);

        // 追加整数部分
        res += to_string(n / d);

        // 恰好整除
        if (n % d == 0)
            return res;

        // 不能整除则由小数部分
        res += '.';

        unordered_map<int, int> map;

        // 模拟除法过程
        for (int64_t r = n % d; r; r %= d)
        {
            // 又再遇到之前遇到过的余数r
            // 表明出现循环，添加括号，并跳出循环
            if (map.count(r) > 0)
            {
                res.insert(map[r], 1, '(');
                res += ')';
                break;
            }

            // 余数r第一次出现，记录其在结果字符串中的位置
            map[r] = res.size();

            r *= 10;

            // 追加10的r除以d的商到结果字符串
            res += to_string(r / d);
        }

        return res;
    }
};