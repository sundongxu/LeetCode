#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// My Version
class Solution
{
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int count = 0;
        vector<int> result = {-1, -1};
        bool isFirst = false;
        int firstPos = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                if (!isFirst)
                {
                    isFirst = true;
                    firstPos = i;
                }
                count++;
            }

            if (count > 0 && nums[i] != target)
            {
                result[0] = i - count;
                result[1] = i - 1;
                return result;
            }
        }

        if (isFirst)
        {
            result[0] = firstPos; // 从第一个元素就是
            result[1] = result[0] + count - 1;
        }

        return result;
    }
};

// // STL
// class Solution
// {
//   public:
//     vector<int> searchRange(vector<int> &nums, int target)
//     {
//         auto lower = lower_bound(nums.begin(), nums.end(), target);
//         auto uppper = upper_bound(lower, nums.end(), target);
//         if (lower == nums.end() || *lower != target)
//             return vector<int>{-1, -1};
//         else
//             return vector<int>{distance(nums.begin(), lower), distance(nums.begin(), prev(uppper))};
//     }
//     template <typename ForwardIterator, typename T>
//     ForwardIterator lower_bound(ForwardIterator first,
//                                 ForwardIterator last, T value)
//     {
//         while (first != last)
//         {
//             auto mid = next(first, distance(first, last) / 2);
//             if (value > *mid)
//                 first = ++mid;
//             else
//                 last = mid;
//         }
//         return first;
//     }
//     template <typename ForwardIterator, typename T>
//     ForwardIterator upper_bound(ForwardIterator first,
//                                 ForwardIterator last, T value)
//     {
//         while (first != last)
//         {
//             auto mid = next(first, distance(first, last) / 2);
//             if (value >= *mid)
//                 first = ++mid; // ̽ lower_bound ϴₓ̼ऻ
//             else
//                 last = mid;
//         }
//         return first;
//     }
// };

int main()
{
    vector<int> nums = {-1};
    Solution s;
    vector<int> result = s.searchRange(nums, 0);
    cout << "[" << result[0] << "," << result[1] << "]" << endl;
    return 0;
}