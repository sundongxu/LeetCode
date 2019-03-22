// 哈希
class Solution
{
  public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> res;

        if (s.size() <= 10)
            return res;

        unordered_map<string, int> map;

        for (int k = 0; k <= s.size() - 10; k++)
            map[s.substr(k, 10)]++;

        for (auto i = map.begin(); i != map.end(); i++)
        {
            if (i->second > 1)
                res.push_back(i->first);
        }
        return res;
    }
};