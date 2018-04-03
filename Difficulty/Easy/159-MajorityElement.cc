/* 
    暴力...哈希表记录每个数字的出现次数
    复杂度嘛...时间O(n)，空间O(n)
 */
class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        map<pair<int, int>> hash_table;
        for (int i = 0; i < nums.size(); i++)
            hash_table[nums[i]]++;
        for (auto p : hash_table)
            if (p.second > nums.size() / 2) // int型除以2本身就是结果向下取整了
                return p.first;
    }
};

/* 
    Moore's Voting Algorithm，参见：http://www.cs.utexas.edu/~moore/best-ideas/mjrty/
    可以在空间复杂度O(1)内做到，前提是有Majority Element，题设条件刚好指明有
 */
class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (count == 0)
            {
                candidate = nums[i];
                count = 1;
            }
            else
            {
                if (nums[i] == candidate)
                    count++;
                else
                    count--;
            }
        }
        return candidate;
    }
};