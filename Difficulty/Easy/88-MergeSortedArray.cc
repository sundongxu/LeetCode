class Solution
{
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // 都放在nums1中，数组元素按升序排列
        int ia = m - 1, ib = n - 1, icur = m + n - 1;
        while (ia >= 0 && ib >= 0)
            nums1[icur--] = nums1[ia] >= nums2[ib] ? nums1[ia--] : nums2[ib--];
        while (ib >= 0)
            nums1[icur--] = nums2[ib--];
    }
};