/* 
    用堆实现，即STL中的优先级队列priority_queue
    最大堆最小堆均可
    桶排序复杂度更低O(n)
 */

// 最大堆，priority_queue默认是最大元素放在队列最前面，很好理解
// 时间复杂度O(nlog(n-k))
class Solution
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int n : nums)
            map[n]++;

        vector<int> res;
        priority_queue<pair<int, int>> pq;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            // 队列里面存的是一个pair，但是第一个元素是数字的出现次数，第二个元素才是数字自身
            // 便于队列按照每个pair元素的第一个元素排序，即按对应数字的出现次数
            pq.push(make_pair(it->second, it->first));

            if (pq.size() > (map.size() - k))
            {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};

// 最小堆
// 时间复杂度O(nlogk)
class Solution
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        priority_queue<int, vector<int>, greater<int>> minHeap; // 最小堆
        for (auto i : nums)
            ++map[i];
        for (auto &i : map)
        {
            minHeap.push(i.second);
            // 最小堆的元素数目保持 <= k
            while (minHeap.size() > k)
                minHeap.pop(); // 将最小元素出队，保证此时堆里还有k个元素，都比它大，即出现次数都比它多
        }                      // 循环结束时，堆里剩下的就是前k个最大元素，即出现次数top k的元素

        vector<int> res;
        for (auto &i : map)
        {
            // 此时堆顶是前k个最大元素里面最小的
            // 遍历map，如元素比堆顶元素大，则一定是前k个最大元素(出现次数最多)之一
            if (i.second >= minHeap.top())
                res.push_back(i.first);
        }
        return res;
    }
};

// 桶排序，很巧妙哟！
// 时间复杂度O(n)
class Solution
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (auto i : nums)
            ++map[i];

        vector<vector<int>> buckets(nums.size() + 1); // nums.size()+1个桶
        for (auto &k : map)
            // 把出现次数相同的数字放入同一个桶
            // 出现次数越多，存储的桶的下标越大
            buckets[k.second].push_back(k.first);

        // 逆序后，buckets中，桶的顺序按数字的出现次数从小到大排列，即下标越小的桶存储的数字的出现次数越多
        reverse(begin(buckets), end(buckets));

        vector<int> res;
        for (auto &bucket : buckets) // 按下标从小到大遍历每个桶
            for (auto i : bucket)
            {
                res.push_back(i);
                if (res.size() == k)
                    return res;
            }

        return res;
    }
};
