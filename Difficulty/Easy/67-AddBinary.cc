static vector<string> strs = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return vector<string>{};
}();

class Solution
{
  public:
    string addBinary(string a, string b)
    {
        string result;
        const size_t n = a.size() > b.size() ? a.size() : b.size(); // n是两者size的较大值
        // 为什么要逆转？一开始高位存储在靠前的位置
        // 而希望从低位开始计算
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        for (size_t i = 0; i < n; i++) // 逆序后，实际是从低位开始计算
        {
            const int ai = i < a.size() ? a[i] - '0' : 0; // ai为a第i为的二进制数值，超出a的位数时为0
            const int bi = i < b.size() ? b[i] - '0' : 0;
            const int val = (ai + bi + carry) % 2;
            carry = (ai + bi + carry) / 2;
            // 每次在result最前面插入当前位计算结果
            // 使得高位最终还是存储在靠前的位置
            result.insert(result.begin(), val + '0');
        }
        if (carry == 1) // 有进位
            result.insert(result.begin(), '1');
        return result;
    }
};