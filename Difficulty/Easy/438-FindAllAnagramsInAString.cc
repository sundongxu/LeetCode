// 26字符
class Solution
{
  public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> pv(26, 0), sv(26, 0), res;
        if (s.size() < p.size())
            return res;
        // fill pv, vector of counters for pattern string and sv, vector of counters for the sliding window
        for (int i = 0; i < p.size(); ++i)
        {
            ++pv[p[i] - 'a'];
            ++sv[s[i] - 'a'];
        }
        if (pv == sv)
            res.push_back(0);

        //here window is moving from left to right across the string.
        //window size is p.size(), so s.size()-p.size() moves are made
        for (int i = p.size(); i < s.size(); ++i)
        {
            // window extends one step to the right. counter for s[i] is incremented
            ++sv[s[i] - 'a'];

            // since we added one element to the right,
            // one element to the left should be forgotten.
            //counter for s[i-p.size()] is decremented
            --sv[s[i - p.size()] - 'a'];

            // if after move to the right the anagram can be composed,
            // add new position of window's left point to the result
            if (pv == sv)
                res.push_back(i - p.size() + 1);
        }
        return res;
    }
};

// 256个字符版本
class Solution
{
  public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> pv(256, 0), sv(256, 0), res;
        if (s.size() < p.size())
            return res;
        for (int i = 0; i < p.size(); ++i)
        {
            ++pv[p[i]]; // pv记录目标字符串p中的全部字符的种类及个数
            ++sv[s[i]]; // sv记录源字符串s中从位置0开始，长度为p.size()长的的子串中全部字符的种类及个数
        }
        if (pv == sv) // 如这都相等，则说明s从位置0开始包含一个p的anagram
            res.push_back(0);

        for (int i = p.size(); i < s.size(); ++i) // 原字符串s从位置p.size()开始，直到末尾
        {
            ++sv[s[i]];
            --sv[s[i - p.size()]]; // sv中添加一个s中位置i的字符s[i]的统计信息，就消去一个在s[i]前面距离p.size()的位置s[i-p.size()]的信息
            // 保证任意时刻，sv中都包含位置 i-p.size()+1 ~ i 共计p.size()个字符，随时可以用于与p对应的pv相匹配
            if (pv == sv)
                res.push_back(i - p.size() + 1);
        }
        return res;
    }
};