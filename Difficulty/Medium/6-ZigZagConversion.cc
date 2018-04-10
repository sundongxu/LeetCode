// 最笨方法，建立一个二维数组，按照之字形顺序将字母加到数组中去，再按行输出即可
// 时间复杂度O(n)，空间复杂度O(n)
class Solution
{
  public:
    string convert(string s, int numRows)
    {
        // 边界条件
        if (numRows <= 1 || s.size() <= 1)
            return s;
        string result;
        vector<vector<char>> vec(numRows);
        int row = 0, step = 1;
        for (int i = 0; i < s.size(); i++)
        {
            vec[row].push_back(s[i]);
            if (row == 0)
                step = 1;
            else if (row == numRows - 1)
                step = -1;
            row += step;
        }

        for (int i = 0; i < numRows; i++)
            for (int j = 0; j < vec[i].size(); j++)
                result += vec[i][j];
        return result;
    }
};

// 巧妙一点，找规律
// 时间复杂度O(n)，空间复杂度O(1)
class Solution
{
  public:
    string convert(string s, int numRows)
    {
        // 边界条件
        if (numRows <= 1 || s.size() <= 1)
            return s;
        string result;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0, index = i; index < s.size();
                 j++, index = (2 * numRows - 2) * j + i)
            {
                result.append(1, s[index]); // 垂直元素
                if (i == 0 || i == numRows - 1)
                    continue;
                if (index + (numRows - i - 1) * 2 < s.size()) // 斜对角元素
                    result.append(1, s[index + (numRows - i - 1) * 2]);
            }
        }
        return result;
    }
};
