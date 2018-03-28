/* 
    夹逼准则，一左一右两个指针
 */
class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        if (height.size() < 2) // 边界条件，size<2都无法组成一个容器，储水体积当然为0
            return 0;
        int left = 0, right = height.size() - 1;
        int volume = 0;
        while (left < right)
        {
            // volume记住循环体中得到的最大容积
            // 容积高度取决于两个下标对应的最小高度
            volume = max(volume, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return volume;
    }
};