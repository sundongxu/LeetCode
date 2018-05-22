#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 头递归 head->recursion
class Solution
{
  public:
    ListNode *temp;
    bool isPalindrome(ListNode *head)
    {
        cout << "isPalindrome(" << head->val << ")" << endl;
        temp = head;
        return check(head, 1);
    }

    bool check(ListNode *p, int count)
    {
        for (int i = 0; i < count; i++)
            cout << '\t';
        // cout << endl;
        if (nullptr == p)
        {
            cout << "check(p = nullptr)";
            cout << endl;
            return true;
        }
        cout << "check(" << p->val << ")";
        cout << endl;

        bool isPal = check(p->next, count + 1) && (temp->val == p->val);
        temp = temp->next;
        for (int i = 0; i < count; i++)
            cout << '\t';
        // cout << endl;
        cout << "check(" << p->val << ")";
        cout << endl;
        return isPal;
    }
};

int main()
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(2);
    ListNode n4(1);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    Solution s;
    if (s.isPalindrome(&n1))
        cout << endl
             << "true";
    else
        cout << endl
             << "false";
    return 0;
}