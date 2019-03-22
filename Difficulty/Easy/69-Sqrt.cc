// My Version
// 二分查找
class Solution
{
  public:
    int mySqrt(int x)
    {
        if (x == 0)
            return x;
        int left = 1, right = x;
        int mid = 0;
        while (1)
        {
            mid = left + (right - left) / 2;
            if (x / mid < mid)
                right = mid - 1;
            else
            {
                if (x / (mid + 1) < mid + 1)
                    return mid;
                left = mid + 1;
            }
        }
    }
};

// Fastest Version
class Solution
{
  public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        int start = 0;
        int end = x;
        while (start < end)
        {
            int mid = (start + end) / 2 + 1; // 可能出现start=0，end=1的情况，mid算出来是0，下面会产生除数为0的错误
            if (mid > (x / mid))
            {
                end = mid - 1;
            }
            else
            {
                if (mid == (x / mid))
                    return mid;
                start = mid;
            }
        }
        return start;
    }
};