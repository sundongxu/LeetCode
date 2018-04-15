// 题目要求：Anagram(回文构词法)，是指打乱字母顺序从而得到全新的单词
// 回文构词法特点：单词里的字母的种类和数目没有改变，只是改变了字母的排列顺序
// 因此将代码按照字母顺序排序后，若它们相等，则属于同一组Anagram
class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> group;
        for (const auto &s : strs)
        {
            string key = s;
            sort(key.begin(), key.end()); // 将每个单词按字母序排序
            group[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto it = group.cbegin(); it != group.cend(); it++)
            if (it->second.size() >= 1)
                result.push_back(it->second);

        return result;
    }
};