/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* 
    递归先
    时间复杂度O(n)，空间复杂度O(1)
 */
class Solution
{
  public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // 边界条件不要漏了k<2，实际就是k=1，根本都不用交换结点位置
        if (head == nullptr || head->next == nullptr || k < 2)
            return head;

        ListNode *next_group = head;
        for (int i = 0; i < k; ++i)
        {
            if (next_group)
                next_group = next_group->next;
            else
                return head;
        }
        // next_group是下一组的第一个结点/头结点
        // new_next_group是下一组逆转后的第一个结点/头结点
        ListNode *new_next_group = reverseKGroup(next_group, k); // 递归调用
        ListNode *prev = NULL, *cur = head;
        while (cur != next_group)
        {
            ListNode *next = cur->next;
            cur->next = prev ? prev : new_next_group;
            prev = cur;
            cur = next;
        }
        return prev; // prev即本组的新头结点
    }
};

/* 
    再迭代
    时间复杂度O(n)，空间复杂度O(1)
 */
class Solution
{
  public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr || k < 2)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        for (ListNode *prev = &dummy, *end = head; end; end = prev->next)
        {
            for (int i = 1; i < k && end; i++)
                end = end->next;
            if (end == nullptr)
                break;                             // ̼不足k个
            prev = reverse(prev, prev->next, end); // 每k个单独逆转一次
        }
        return dummy.next;
    }

    // prev是begin(首元素)前一个元素，[begin, end]闭区间逆转次序，保证三者都不为nullptr
    ListNode *reverse(ListNode *prev, ListNode *begin, ListNode *end)
    {
        ListNode *end_next = end->next;
        for (ListNode *p = begin, *cur = p->next, *next = cur->next;
             cur != end_next;
             p = cur, cur = next, next = next ? next->next : nullptr)
        {
            cur->next = p;
        }
        begin->next = end_next;
        prev->next = end;
        return begin;
    }
}