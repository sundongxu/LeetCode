class Solution
{
  public:
    int evalRPN(vector<string> &tokens)
    {
        int x, y;
        auto token = tokens.back();
        tokens.pop_back();

        if (is_operator(token))
        {
            y = evalRPN(tokens); // 取出操作数
            x = evalRPN(tokens);
            if (token[0] == '+')
                x += y;
            else if (token[0] == '-')
                x -= y;
            else if (token[0] == '*')
                x *= y;
            else
                x /= y;
        }
        else
        {
            x = stoi(token);
        }
        return x;
    }

    bool is_operator(const string &op)
    {
        return op.size() == 1 && string("+-*/").find(op) != string::npos;
    }
};