/* 
    要求空间复杂度为O(1)，in-place
    方法很多，至少3种
 */
// 下标 + k 对数组长度取模
class Solution
{
  public:
    void rotate(vector<int> &nums, int k)
    {
        // 边界条件，最后再来看看能不能合并到普通情况
        int len = nums.size();
        if (len < 2 || k == 0)
            return;

        int nowIndex = 0; // 当前要修改的位置
        int tmp1, tmp2 = nums[0];
        for (int j = 0, i = 0; j < len; j++)
        {
            tmp1 = tmp2;
            nowIndex = (k + nowIndex) % len;
            tmp2 = nums[nowIndex];
            nums[nowIndex] = tmp1;
            if (nowIndex == i) // 这一步很关键
            // 之前一轮已经完成从位置i开始的元素的移动了
            // 即位置i在序列中的下一个位置已经被之前在位置i的元素修改了
            // 如再从位置i开始，又会将其在序列中的下一个目的位置再次用位置i的新元素再度修改
            // 此时应该从位置i后移一位，从位置i+1触发继续元素移动
            // 进一步思考可以发现，只要经过一圈又到达之前到过的位置，那么都需要这一步
            // 只要数组长度为k的整数倍，都会出现此情况，此时将下一步要修改的位置往后移动一位即可
            {
                nowIndex = ++i;
                tmp2 = nums[nowIndex];
            }
        }
    }
};