// 排序法
// 时间复杂度O(nlogn) -> 排序过程，空间复杂度即copy，为O(n)
class Solution
{
  public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> copy(nums);
        sort(copy.begin(), copy.end());
        int start = copy.size() - 1, end = 0;

        for (int i = 0; i < copy.size(); i++)
        {
            if (nums[i] != copy[i])
            {
                start = min(start, i);
                end = max(end, i);
            }
        }
        return end - start >= 0 ? end - start + 1 : 0;
    }
};

// 栈法
class Solution
{
  public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        stack<int> s;
        int l = nums.size(), r = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!s.empty() && nums[s.top()] > nums[i])
            {
                l = min(l, s.top());
                s.pop();
            }
            s.push(i);
        }

        while (!s.empty())
            s.pop();

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!s.empty() && nums[s.top()] < nums[i])
            {
                r = max(r, s.top());
                s.pop();
            }
            s.push(i);
        }

        return r - l > 0 ? r - l + 1 : 0;
    }
};

// 无须辅助空间的方法
class Solution
{
  public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        // 空间复杂度为O(1)的方法
        int smallest = INT_MAX, biggest = INT_MIN;
        bool flag = false;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
                flag = true;
            if (flag)
                smallest = min(smallest, nums[i]);
        }
        flag = false;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] > nums[i + 1])
                flag = true;
            if (flag)
                biggest = max(biggest, nums[i]);
        }
        int l, r;
        for (l = 0; l < nums.size(); l++)
        {
            if (smallest < nums[l])
                break;
        }
        for (r = nums.size() - 1; r >= 0; r--)
        {
            if (biggest > nums[r])
                break;
        }
        return r - l < 0 ? 0 : r - l + 1;
    }
};