// 找比相邻元素大的元素下标，数组相邻元素不相等，要求logn的复杂度
// 二分查找，递归版
class Solution
{
  public:
    int findPeakElement(vector<int> &num)
    {
        return Helper(num, 0, num.size() - 1);
    }

    int Helper(const vector<int> &num, int low, int high)
    {
        if (low == high)
            return low;
        else
        {
            int mid1 = (low + high) / 2;
            int mid2 = mid1 + 1;
            if (num[mid1] > num[mid2])
                return Helper(num, low, mid1);
            else
                return Helper(num, mid2, high);
        }
    }
};

// 二分查找，迭代
class Solution
{
  public:
    int findPeakElement(const vector<int> &num)
    {
        int low = 0;
        int high = num.size() - 1;

        while (low < high)
        {
            int mid1 = (low + high) / 2;
            int mid2 = mid1 + 1;
            if (num[mid1] < num[mid2])
                low = mid2;
            else
                high = mid1;
        }
        return low;
    }
};

class Solution
{
  public:
    int findPeakElement(const vector<int> &num)
    {
        int low = 0, high = num.size() - 1;
        while (low < high - 1)
        {
            int mid = (low + high) / 2;
            if (num[mid] > num[mid - 1] && num[mid] > num[mid + 1])
                return mid;
            else if (num[mid] > num[mid + 1])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return num[low] > num[high] ? low : high;
    }
};