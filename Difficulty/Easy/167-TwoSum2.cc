#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> result;
        unordered_map<int, int> map;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (map[target - numbers[i]])
            {
                result.push_back(map[target - numbers[i]]);
                result.push_back(i + 1);
                break;
            }
            else
            {
                map[numbers[i]] = i + 1;
            }
        }
        return result;
    }
};