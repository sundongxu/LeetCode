class Solution
{
  public:
    int removeElement(vector<int> &nums, int val)
    {
        int index = 0; // 用来记录新数组当前要插入的位置
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != val)
                nums[index++] = nums[i];
        return index;

        // 直接用STL解决，remove将nums中的指定值的元素删除，返回指向新数组最后一个元素的迭代器
        // return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
    }
};