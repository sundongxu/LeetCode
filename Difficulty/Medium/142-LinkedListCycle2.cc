/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* 
    分析如下：
    当fast与slow相遇时，slow肯定没有遍历完链表，而fast已经在环内循环了，而两者相遇一定是在环内某处
    那么设fast已经在环内循环了n圈(n>=1)，再设slow走了s步，则fast走了2s步
    而fast的总步数还应该等于s加上fast在环内多转的n圈的长度，设环长为r，则有：2s = s + nr => s = nr
    设整个链表长度为L，环入口点与相遇点的距离为a，起点到环入口点距离为x，则有：
    x + a = s = nr = (n-1)*r + r = (n-1)*r + L - x => x = (n-1)*r + (L-x-a)
    L-x-a 为相遇点到环入口点的距离，由此可知，从链表头到环入口点的距离 等于 n-1倍环长 + 相遇点到环入口点距离 
    于是，在fast与slow相遇时，再设一指针slow2指向head，此后slow与slow2分别以一次一步的速度前进，、
    则两者一定会在环入口处相遇，根据就是上述推理得到的：
    slow在本圈内剩余距离(即其当前位置到环入口点的距离)与slow2从head开始到环入口的距离相等
    若相遇，则返回slow或slow2指针，即为环开始的起始结点
 */
class Solution
{
  public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                ListNode *slow2 = head;
                while (slow2 != slow)
                {
                    slow2 = slow2->next;
                    slow = slow->next;
                }
                return slow2;
            }
        }
        return nullptr;
    }
};