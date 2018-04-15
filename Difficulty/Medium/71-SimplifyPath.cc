class Solution
{
  public:
    string simplifyPath(string path)
    {
        vector<string> dirs; // 当做栈

        for (auto i = path.begin(); i != path.end();)
        {
            i++; // 跳过第一个字符(肯定是'/')

            auto j = find(i, path.end(), '/'); // 找到下一个'/'
            auto dir = string(i, j);

            if (!dir.empty() && dir != ".")
            {
                if (dir == "..")
                {
                    if (!dirs.empty())
                        dirs.pop_back();
                }
                else
                    dirs.push_back(dir);
            }
            i = j; // i跳转至j，即下一个'/'
        }

        stringstream ss;
        if (dirs.empty())
            ss << "/";
        else
            for (auto dir : dirs)
                ss << '/' << dir;
        return ss.str();
    }
};