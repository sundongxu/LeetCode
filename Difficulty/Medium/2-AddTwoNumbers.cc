/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// My Version
class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode head(1); // 头结点
        int carry = 0;
        ListNode *prev = &head;
        // 数位都是逆序存储，也就是较低的数位存储在链表中靠前的位置
        for (ListNode *p1 = l1, *p2 = l2;
             p1 != nullptr || p2 != nullptr;
             p1 = p1 == nullptr ? nullptr : p1->next,
                      p2 = p2 == nullptr ? nullptr : p2->next,
                      prev = prev->next)
        {
            const int d1 = p1 == nullptr ? 0 : p1->val;
            const int d2 = p2 == nullptr ? 0 : p2->val;
            const int d = (d1 + d2 + carry) % 10;
            carry = (d1 + d2 + carry) / 10;
            prev->next = new ListNode(d);
        }
        if (carry > 0)
            prev->next = new ListNode(carry);
        return head.next;
    }
};

// 递归

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return helper(l1, l2, 0);
    }

  private:
    ListNode *helper(ListNode *l1, ListNode *l2, int carry)
    {
        if (l1 == NULL && l2 == NULL)
            return 0 == carry ? NULL : new ListNode(carry);
        if (l1 == NULL && l2 != NULL)
            l1 = new ListNode(0);
        if (l1 != NULL && l2 == NULL)
            l2 = new ListNode(0);

        int sum = l1->val + l2->val + carry;
        ListNode *curr = new ListNode(sum % 10);
        curr->next = helper(l1->next, l2->next, sum / 10); // 递归
        return curr;
    }
};