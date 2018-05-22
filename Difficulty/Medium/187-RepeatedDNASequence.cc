// 哈希
class Solution
{
  public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> res;
        if (s.size() <= 10)
            return res;
        unordered_map<string, int> m;

        for (int k = 0; k < s.size() - 9; k++)
            m[s.substr(k, 10)]++;

        for (auto i = m.begin(); i != m.end(); i++)
        {
            if (i->second > 1)
                res.push_back(i->first);
        }
        return res;
    }
};