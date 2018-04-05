/* 
    最基本的想法，每次拿出n的当前位，加到一个变量result中去
    每次用完n的当前低位后，都要将n右移一位以抹去该低位
    每次将当前位加到result中之前，先要将result左移一位
    以多出一个0用于与当前位相加，且之前在n中的低位变成result中的高位
 */
class Solution
{
  public:
    uint32_t reverseBits(uint32_t n)
    {
        int result = 0;
        int count = 0;
        int curBit = 0;
        while (count < 32) // 遍历每一位
        {
            curBit = n & 1;                  // 得到n的当前低位
            result = (result << 1) + curBit; // result右移一位后与n的当前位相加
            n = n >> 1;                      // n右移一位以抹去已经用过的低位
            count++;
        }
        return result;
    }
};

/* 
    很巧妙的思想，交换对称位置即可达到逆转整个数的目的
 */
class Solution
{
  public:
    uint32_t reverseBits(uint32_t n)
    {
        for (int i = 0; i < 16; i++)
            n = swapBits(n, i, 32 - i - 1); // 交换对称位
        return n;
    }

    uint32_t swapBits(int n, int i, int j)
    {
        int a = (n >> i) & 1;                // 得到第i位的比特
        int b = (n >> j) & 1;                // 得到第j位的比特
        if ((a ^ b) != 0)                    // 位异或，两者不同才需要互换
            return n ^= (1 << i) | (1 << j); // 逆转对称位
        // 原本的0与1异或后变为1，原本的1与1异或后变为0
        return n;
    }
};
