class Solution
{
  public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> vs;
        string s = "";
        for (int &num : nums)
            vs.push_back(to_string(num));
        sort(vs.begin(), vs.end(), [](string a, string b) { return a + b > b + a; });  // lambda表达式，字符串比较
        if (vs[0][0] == '0')
            return "0"; //deal with all "0" value
        for (string &ss : vs)
            s += ss;
        return s;
    }
};