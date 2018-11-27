/* 
    两个栈来实现...好吧，用栈实现栈，是Discuss中票数最高的C++代码了
    非常容易理解，栈s1存储全部元素，而栈s2只会把最小的元素压栈
    且s2栈顶永远是最小元素，getMin()从而可以在常数时间完成
    新元素入栈时，s1总是将元素入栈，s2则只在为空或该元素小于等于最小元素即s2栈顶元素时才入栈
    元素出栈时，s1总是将元素出栈，而只有当该元素为最小元素时，s2才会也将其栈顶元素出栈
 */
class MinStack
{
  private:
    stack<int> s1;
    stack<int> s2;

  public:
    /** initialize your data structure here. */
    MinStack() = default;

    void push(int x)
    {
        s1.push(x);
        if (s2.empty() || x <= getMin())
            s2.push(x);
    }

    void pop()
    {
        if (s1.top() == getMin())
            s2.pop();
        s1.pop();
    }

    int top()
    {
        return s1.top();
    }

    int getMin()
    {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

/* 
    如果觉得上面的两个栈的方法太过明目张胆了...那你就用vector代替栈吧
    其实没啥差别，反正都已经用了STL...
    思想也基本一样，数组a存储全部元素，而数组min则只存储当前最小元素
    且min的尾元素永远是最小元素，getMin()故而可以在常数时间完成
    插入新元素时，数组a总是将元素插入到尾部，min则只在该元素小于最小元素即min尾元素时才将新元素插入到尾部
    否则就把最小元素再次插入到尾部，等于说尾部可能有多个重复的最小元素
    元素删除时，由于之前a与min都插入了等数目的元素，故两者都可以放心地从尾部删除元素

 */
class MinStack
{
  public:
    vector<int> a;
    vector<int> min;
    MinStack()
    {
        min.push_back(2147483647); // INT_MAX
    }
    void push(int x)
    {
        a.push_back(x);
        if (x < min.back())
        {
            min.push_back(x);
        }
        else
        {
            min.push_back(min.back()); // 将最小元素再次插入到尾部，有重复
            // 但这样保证每次push操作，a和min都会在尾部插入新元素
            // 从而后面的pop操作两者都可以放心的删除尾部元素
        }
    }

    void pop()
    {
        a.pop_back(); // 将vector的尾部当做栈顶，元素从尾部插入，也先从尾部删除
        min.pop_back();
    }

    int top()
    {
        return a.back();
    }

    int getMin()
    {
        return min.back();
    }
};