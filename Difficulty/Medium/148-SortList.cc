/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 单链表适合用归并排序，双向链表适合用快速排序
// 归并排序正好是原地排序的，空间复杂度为O(1),时间复杂度为O(nlogn)
class Solution
{
  public:
    ListNode *sortList(ListNode *head) // 头指针指向的头结点就是一个有意义的结点(有数据val)
    {
        // 边界条件判定，当头指针为空或只有一个结点时(已经有序)，返回head自身
        if (head == nullptr || head->next == nullptr)
            return head;

        // 快慢指针找到中间结点
        ListNode *fast = head, *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next; // fast快指针以两倍速度后移
            slow = slow->next;       // slow慢指针以一倍速度后移
        }

        // 断开
        fast = slow;
        slow = slow->next;
        fast->next = nullptr;

        ListNode *l1 = sortList(head); // 前半段排序
        ListNode *l2 = sortList(slow); // 后半段排序
        return mergeTwoLists(l1, l2);
    }

    // 合并两个有序链表
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode head(-1);
        for (ListNode *p = &head; l1 != nullptr || l2 != nullptr; p = p->next)
        {
            int val1 = l1 == nullptr ? INT_MAX : l1->val;
            int val2 = l2 == nullptr ? INT_MAX : l2->val;
            if (val1 <= val2)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
        }
        return head.next;
    }
};