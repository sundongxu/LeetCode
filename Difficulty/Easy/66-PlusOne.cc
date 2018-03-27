class Solution
{
  public:
    vector<int> plusOne(vector<int> &digits)
    {
        add(digits, 1);
        return digits;
    }

  private:
    void add(vector<int> &digits, int digit)
    {
        int c = digit;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it)
        {
            *it += c;
            c = *it / 10; // 有进位则为1，无进位则为0
            *it %= 10;
        }

        if (c > 0)
            digits.insert(digits.begin(), 1);
    }
};

// lambda Version
class Solution
{
  public:
    vector<int> plusOne(vector<int> &digits)
    {
        add(digits, 1);
        return digits;
    }

  private:
    void add(vector<int> &digits, int digit)
    {
        int c = digit;

        for_each(digits.rbegin(), digits.rend(), [&c](int &d) {
            d += c;
            c = d / 10; // 有进位则为1，无进位则为0
            d %= 10;
        });

        if (c > 0)
            digits.insert(digits.begin(), 1);
    }
};