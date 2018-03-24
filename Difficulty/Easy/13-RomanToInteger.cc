class Solution
{
  public:
    inline int map(const char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }
    }

    int romanToInt(string s)
    {
        int result = 0;
        for (size_t i = 0; i < s.size(); ++i)
            if (i > 0 && map(s[i]) > map(s[i - 1]))
                // 如果上一位大于当前位
                // 那么这段的值不仅要用当前位的值减去减去上一位的值，还要减去之前先访问上一位时加上的该位的值
                // 等于说要减2倍的上一位的值
                result += (map(s[i]) - 2 * map(s[i - 1]));
            else
                result += map(s[i]);
        return result;
    }
};