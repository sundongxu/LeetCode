/* 
    题目要求：将当前排列变为全部排列中按字母序从小到大的当前排列的下一个排列
    如给定排列在全部排列中按字母序已经是最大的，则返回最小的排列，如3,2,1->1,2,3
    元素位置更换必须就地进行，不能额外开辟空间，即空间复杂度O(1)
    思想：
    如果一个排列已经是完全的降序排列，则直接逆转该序列得到最小排列，返回符合题意
    如果一个排列不是完全的降序排列，要找它的下一个排列，可以这样找：
    从右往左遍历，一定可找到一个位置i，使得其右边的元素比它大，即nums[i] < nums[i+1]
    那么元素nums[i]一定是要被交换的一个元素，下面在i的右边找一个比它大，但是却是i右边子序列里面最小的数
    即在位置i右边找一个刚好比nums[i]的数，找到该位置j，交换元素nums[i]和nums[j]
    但是此时i右边子序列原本就是降序排列的，现在改大了位置i的元素值，
    则按字母序的下一个排列应该将位置i右边的子序列变为升序排列(子序列中最小的排列即升序排列)
 */
class Solution
{
  public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) // 从右往左遍历
            i--;
        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) // 从右往左找到i右边比nums[i]大且最小的元素nums[j]
                j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
        // 也能处理
    }
};