#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // 边界条件检查，有指针就要判空
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode dummy(-1);
        ListNode *cur = &dummy; // p指向dummy结点，但之后p后移，而dummy结点仍旧是头结点
        // 注意这个头结点不是l1或者l2中的任何元素，返回的时候应该是从dummy.next开始返回
        for (; l1 != nullptr && l2 != nullptr; cur = cur->next)
            if (l1->val > l2->val)
            {
                cur->next = l2;
                l2 = l2->next;
            }
            else
            {
                cur->next = l1;
                l1 = l1->next;
            }
        cur->next = l1 != nullptr ? l1 : l2; // 把元素没用完的list接在最后
        return dummy.next;                   // 返回p? 返回&dummy?
    }

    // 解法一：相邻链表两两归并，效率较低
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // 首先边界检查，有容器就要判空
        if (lists.empty())
            return nullptr;
        ListNode *cur = lists[0];

        for (int i = 1; i < lists.size(); ++i)
            cur = mergeTwoLists(cur, lists[i]);
        return cur;
    }

    // 解法二：分治法，类似归并排序思想，不断对半划分，如n个链表先划分为合并n/2个链表
    // 再继续划分，直至划分成只有一个或两个链表的任务，开始合并
    // 难点在于确定两两如何配对，按k的奇偶性来决定，两两合并的链表的位置相隔(n+1)/2
    // 如n=6，则(n+1)/2=3，则0和3、1和4、2和5两两合并，即n为偶数时恰好可以分成整数个包含两个链表的组
    // 如n=5，则(n+1)/2=3。则0和3、1和4两两合并，5落单，即n为奇数时可分为若干个包含两个链表的组，另有一个链表落单
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        int n = lists.size(); // n表示当前待合并链表个数
        while (n > 1)
        {
            int k = (n + 1) / 2;
            for (int i = 0; i < n / 2; ++i)
            {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }

    // 解法三：最小堆（即优先队列，使用greater函数）
    // 首先把k个链表的首元素都加入到堆中，它们会自动排好序
    // 然后每次取出最小的元素加入到最终的结果链表中去，并将所取出元素在其所属链表中的下一个元素
    // 再加入堆中，之后仍从堆中取出最小元素，以此类推，直至堆中没有元素，此时k个链表合并也完成了
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto greater = [](ListNode *&a, ListNode *&b) {
            return a->val > b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(greater)> q(greater);
        for (auto node : lists)
            if (node != nullptr)
                q.push(node); // 各链表首元素入队

        ListNode dummy(-1);
        ListNode *cur = &dummy;

        while (!q.empty())
        {
            auto min = q.top();
            q.pop();
            cur->next = min;
            cur = cur->next;
            if (cur->next != nullptr)
                q.push(cur->next);
        }

        return dummy.next;
    }

    // 解法四：混合排序，递归，分治法的一种
    // 将原链表分成两段，然后对每段调用递归函数
    // 递归关键在于我们假设返回的left和right已经合并好了，然后再对left和right进行合并
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return helper(lists, 0, (int)lists.size() - 1);
    }

    ListNode *helper(vector<ListNode *> &lists, int start, int end)
    {
        if (start > end)
            return nullptr;
        if (start == end)
            return lists[start];
        int mid = (start + end) / 2;
        ListNode *left = helper(lists, start, mid);
        ListNode *right = helper(lists, mid + 1, end);
        return mergeTwoLists(left, right);
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

    // 解法五：计数排序
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode dummy(-1), *cur = &dummy;
        unordered_map<int, int> m;
        int mx = INT_MIN, mn = INT_MAX;
        for (auto node : lists)
        {
            ListNode *p = node;
            while (p != nullptr)
            {
                mx = max(mx, p->val);
                mn = min(mn, p->val);
                m[p->val]++;
                p = p->next;
            }
        }
        for (int i = mn; i <= mx; ++i)
        {
            if (m.count(i) == 0)
                continue;
            for (int j = 0; j < m[i]; ++j)
            {
                cur->next = new ListNode(i);
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};