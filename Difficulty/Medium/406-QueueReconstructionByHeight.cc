class Solution
{
  public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people)
    {
        // 先排序，按照高度排序，从矮到高，如高度h相同，则k小的排前面
        sort(people.begin(), people.end(), [](pair<int, int> p1, pair<int, int> p2) {
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        });

        vector<pair<int, int>> sol;
        for (auto person : people)
            sol.insert(sol.begin() + person.second, person);
            
        return sol;
    }
};