/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* 
    要求：
    不能改变两个链表的原有结构，假设两者都无环
    时间复杂度要求O(n)，空间复杂度O(1)
    无相交结点返回nullptr

    分析：
    两个list在相交结点之后的长度是一样的， 而在相交结点之前的长度不一样
    的， 那么找出两者总长度的差diff，也就是两者在相交结点前的长度之差 
    先让较长list的指针往后移diff的距离，然后再两者同时后移，指针值相等处即相交结点
 */
class Solution
{
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *pa = headA;
        ListNode *pb = headB;
        int lenA = 0, lenB = 0;
        while (pa != nullptr)
        {
            lenA++;
            pa = pa->next;
        }
        while (pb != nullptr)
        {
            lenB++;
            pb = pb->next;
        }
        pa = headA;
        pb = headB;
        int diff = abs(lenA - lenB);
        if (lenA > lenB)
        {
            // A长于B，则A向后移动diff个位置
            while (diff > 0)
            {
                diff--;
                pa = pa->next;
            }
        }
        else
        {
            // B长于A，或等长度，让B后移diff个位置
            while (diff > 0)
            {
                diff--;
                pb = pb->next;
            }
        }

        // 此时pa和pb到交集结点的距离相等，同时后移直至指向同一结点
        // 如到各自末尾还未找到汇合结点，则返回nullptr
        for (; pa != nullptr && pb != nullptr; pa = pa->next, pb = pb->next)
            if (pa == pb)
                return pa;
        return nullptr;
    }
};