class Solution
{
  public:
    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0)
            return result;

        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) { return nums1[a.first] + nums2[a.second] >
                                                                                  nums1[b.first] + nums2[b.second]; };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
        min_heap.emplace(0, 0);
        while (k-- > 0 && min_heap.size())
        {
            auto idx_pair = min_heap.top();
            min_heap.pop();
            result.emplace_back(nums1[idx_pair.first], nums2[idx_pair.second]);
            if (idx_pair.first + 1 < nums1.size())
                min_heap.emplace(idx_pair.first + 1, idx_pair.second);
            if (idx_pair.first == 0 && idx_pair.second + 1 < nums2.size())
                min_heap.emplace(idx_pair.first, idx_pair.second + 1);
        }
        return result;
    }
};

class Solution
{
  public:
    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> res;
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        k = min(k, m * n);
        vector<int> indice(m, 0);
        while (k-- > 0)
        {
            int tmp_index = 0;
            long tmp_sum = LONG_MAX;
            for (int i = 0; i < m; i++)
            {
                if (indice[i] < n && tmp_sum >= nums1[i] + nums2[indice[i]])
                {
                    tmp_index = i;
                    tmp_sum = nums1[i] + nums2[indice[i]];
                }
            }
            res.push_back(make_pair(nums1[tmp_index], nums2[indice[tmp_index]]));
            indice[tmp_index]++;
        }
        return res;
    }
};

// Priority Queue
class Solution
{
  public:
    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> v;
        if (nums1.empty() || nums2.empty())
            return v;
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) { return a.first + a.second > b.first + b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
        for (auto n : nums1)
            for (auto m : nums2)
                minHeap.emplace(n, m);
        while (minHeap.size() && k--)
        {
            v.emplace_back(minHeap.top());
            minHeap.pop();
        }
        return v;
    }
};

// Index Array
class Solution
{
  public:
    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> v;
        if (nums1.empty() || nums2.empty())
            return v;
        int indexes[nums1.size()]{0};
        int size = min(k, int(nums1.size() * nums2.size()));
        while (size)
        {
            int t = INT_MAX;
            for (int i = 0; i < nums1.size(); ++i)
            {
                if (indexes[i] == nums2.size())
                    continue;
                t = min(t, nums1[i] + nums2[indexes[i]]);
            }
            for (int i = 0; i < nums1.size(); ++i)
            {
                if (indexes[i] < nums2.size() && nums1[i] + nums2[indexes[i]] == t)
                    v.emplace_back(nums1[i], nums2[indexes[i]++]), size--;
                if (!size)
                    return v;
            }
        }
        return v;
    }
};

// Combination
class Solution
{
  public:
    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> v;
        if (nums1.empty() || nums2.empty())
            return v;
        auto cmp = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b) { return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
        minHeap.emplace(0, 0);
        while (minHeap.size() && k--)
        {
            auto t = minHeap.top();
            minHeap.pop();
            v.emplace_back(nums1[t.first], nums2[t.second]);
            if (t.first < nums1.size() - 1)
                minHeap.emplace(t.first + 1, t.second);
            if (t.first == 0 && t.second < nums2.size() - 1)
                minHeap.emplace(t.first, t.second + 1);
        }
        return v;
    }
};

class Solution
{
  private:
    struct mycompare
    {
        bool operator()(pair<int, int> &p1, pair<int, int> &p2)
        {
            return p1.first + p1.second < p2.first + p2.second;
        }
    };

  public:
    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> pq;
        for (int i = 0; i < min((int)nums1.size(), k); i++)
        {
            for (int j = 0; j < min((int)nums2.size(), k); j++)
            {
                if (pq.size() < k)
                    pq.push(make_pair(nums1[i], nums2[j]));
                else if (nums1[i] + nums2[j] < pq.top().first + pq.top().second)
                {
                    pq.push(make_pair(nums1[i], nums2[j]));
                    pq.pop();
                }
            }
        }
        while (!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};