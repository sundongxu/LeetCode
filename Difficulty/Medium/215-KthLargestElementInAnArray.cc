/* 
    最笨的，直接排序，返回倒数第k个
    时间复杂度即sort排序(STL中默认是迭代版的归并排序)的时间复杂度O(nlogn)，空间复杂度O(1)
 */
class Solution
{
  public:
    int findKthLargest(vector<int> &nums, int k)
    {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n - k];
    }
};

/* 
    最小堆(优先队列)，每次出队头元素，出k次
 */
class Solution
{
  public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap; // 最小堆
        for (int val : nums)
        {
            minHeap.push(val);

            if (minHeap.size() > k) // 始终保持最小堆里有k个元素
            {
                minHeap.pop(); //每次删除堆顶最小的，剩余的是前k个最大元素
            }
        }
        return minHeap.top(); // 但是堆顶恰好是这前k个最大元素里面最小的，堆顶元素即第k大元素
    }
};
