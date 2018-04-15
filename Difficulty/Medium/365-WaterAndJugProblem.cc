// 题目要求：现有两个容量分别为x和y的容器可以盛水
// 允许的操作：要么盛满，要么倒空
// 还可以从一个容器倒水至另一个容器，至源容器为空，或目标容器满
// 问能否准确量出容积z的水
// 要求最后这容积为z的水，可以只在一个容器内，也可以是两容器中水容积之和

// 参见：https://leetcode.com/problems/water-and-jug-problem/discuss/83720/Clear-Explanation-of-Why-Using-GCD
// 思想：不去考虑两个容器倒来倒去的情况，假设我们有一个足够大的容器，和两个容积分别为x和y的容器
// 每次都将两个小容器中的水倒入大容器，或从大容器直接倒出水
// 那么本题等价于让这个足够大的容器最后剩下容积为z的水，允许对容积为x和y的容积分别采取倒满、倒空两种操作
// 得到等式 z = m * x + n * y，其中m和n均为整数，且很明显z<=x+y时才能量出容积为z的水
// 即“倒入”m次x，“倒入”n次y
// “倒入”用引号是说明：真实倒入大容器就是+x或+y，从大容器倒出就是-x或-y
// 根据数学知识(https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity)
// 当d=gcd(x,y)时，总是可以找到满足ax + by = d的整数a与b
// 那么如果 z % d == 0，有：(a*z/d)*x + (b*z/d)*y = z，即m = a*z/d，n=b*z/d
class Solution
{
  public:
    bool canMeasureWater(int x, int y, int z)
    {
        return z == 0 || (z <= x + y && z % gcd(x, y) == 0);
    }

  private:
    int gcd(int x, int y)
    {
        return y == 0 ? x : gcd(y, x % y);
    }
};

class Solution
{
  public:
    bool canMeasureWater(int x, int y, int z)
    {
        if (x + y == z)
            return true;
        if (x + y < z)
            return false;
        if (x > y) // x永远是更小的容器容积
        {
            int temp = x;
            x = y;
            y = temp;
        }
        int volume = 0; // 代表整个操作过程中两个容积之和
        while (1)
        {
            if (volume < x)
                volume += y;
            else
                volume -= x;
            if (volume == z)
                return true;
            if (volume == 0)
                return false;
        }
    }
};