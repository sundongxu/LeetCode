#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
  public:
    // int titleToNumber(string s)
    // {
    //     int result = 0;
    //     for (int i = 0; i < s.size(); result = result * 26 + (s.at(i) - 'A' + 1), i++)
    //         ;
    //     return result;
    // }

    int titleToNumber(string s)
    {
        int i = 0, sum = 0;
        for (; i < s.size(); i++)
            sum = sum + pow(26, s.size() - i - 1) * (s[i] - 'A' + 1);
        return sum;
    }
};

int main()
{
    Solution s;
    cout << s.titleToNumber("AAB") << endl;
}