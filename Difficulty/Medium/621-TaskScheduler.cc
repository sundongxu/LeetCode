// 决定总完成时间往往在于出现次数最多的任务
// 因为其存在冷却间隔，在冷却间隔里处理其它任务，如果在冷却间隔里恰好处理完了全部其它任务，那么最后一个周期一定处理的是出现次数最多的任务
// 当然也可能任务总个数很多，以至于在完成了出现次数最多的任务后还有任务未完成，还需要更多周期
// 如AAABBCCDD...，这种情况，此时花的时间不难发现规律：总周期数恰好是任务总个数
class Solution
{
  public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> mp;  // 任务名 -> 相同任务个数
        int count = 0;
        for (auto e : tasks)  // 统计不同任务种类
        {
            mp[e]++;
            count = max(count, mp[e]);
        }
        // count为出现次数最多的任务(设为A)，出现的次数

        int ans = (count - 1) * (n + 1);  // 要完成count-1次任务A至少要花这么多时间
        for (auto e : mp)
            if (e.second == count)  // 可能有多个出现次数都为最大次数的任务，每发现一个这样的任务就增加一个时间片
                ans++;
        return max((int)tasks.size(), ans);
    }
};