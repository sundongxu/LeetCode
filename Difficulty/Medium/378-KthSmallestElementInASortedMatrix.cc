// 题目要求：矩阵的每一行、每一列元素值都是按升序排列
// 找出第k小的元素，即从小到大第k个元素值
// 每一行每一列都有序，想到用二分查找
class Solution
{
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        const int n = matrix.size();
        int le = matrix[0][0], ri = matrix[n - 1][n - 1];
        int mid = 0;

        while (le < ri)
        {
            mid = (le + ri) / 2; // mid = le + (ri - le) / 2
            int num = 0;
            for (int i = 0; i < n; i++) // 遍历所有行
            {
                // 在第i行中遍历所有列元素
                int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                num += pos;
            }
            if (num < k)
                le = mid + 1;
            else // num >= k
                ri = mid;
        }
        return le;
    }
};

class Solution
{
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();

        int left = matrix[0][0];          // 矩阵最小元素值
        int right = matrix[n - 1][n - 1]; // 矩阵最大元素值

        while (left < right)
        {
            int mid = (left + right) / 2;

            int count = 0;              // 不超过mid的元素个数
            for (int i = 0; i < n; i++) // 遍历每一行
            {
                vector<int> &row = matrix[i];
                // upper_bound()返回指向第一个超过mid的元素的迭代器
                // count加上当前行中不超过mid的元素个数
                count += upper_bound(row.begin(), row.end(), mid) - row.begin();
            }

            if (count < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

class Solution
{
  public:
    struct compare
    {
        bool operator()(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
        {
            return a.first > b.first;
        }
    };
    int kthSmallest(vector<vector<int>> &arr, int k)
    {

        int n = arr.size(), m = arr[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> p;
        // priority_queue< pair<int,pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int,pair<int, int> >>> p;

        for (int i = 0; i < n; i++)
            p.push(make_pair(arr[i][0], make_pair(i, 0)));

        int x = k, ans;
        while (x--)
        {
            int e = p.top().first;
            int i = p.top().second.first;
            int j = p.top().second.second;
            ans = e;
            p.pop();
            if (j != m - 1)
                p.push(make_pair(arr[i][j + 1], make_pair(i, j + 1)));
        }
        return ans;
    }
};