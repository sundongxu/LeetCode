#include <string>
#include <stack>

using namespace std;

class Solution
{
  public:
    bool isValid(string s)
    {
        string left = "([{";
        string right = ")]}";
        stack<char> stk;

        for (auto c : s)
            if (left.find(c) != string::npos) // 在left中能找到c，即c是左括号
                stk.push(c);
            else                                                     // c不是左括号，即c是右括号
                if (stk.empty() || stk.top() != left[right.find(c)]) // 栈为空或栈顶元素不是对应当前右括号的左括号
                return false;
            else
                stk.pop();
        return stk.empty(); // 是否匹配完全
    }
};