/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution
{
  public:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        vector<Interval> result;
        for (int i = 0; i < intervals.size(); i++)
            insert(result, intervals[i]);
        return result;
    }

  private:
    void insert(vector<Interval> &result, Interval newInterval)
    {
        auto it = result.begin();
        while (it != result.end())
        {
            if (newInterval.end < it->start)
            {
                // 新interval完全在当前interval的左边，应将新interval插入在当前interval之前位置
                result.insert(it, newInterval);
                return;
            }
            else if (newInterval.start > it->end)
            {
                // 新interval完全在当前Interval的右边
                it++;
                continue;
            }
            else
            {
                // 两者有重叠部分，此时需要合并时段
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
                it = result.erase(it);
            }
        }
        result.insert(result.end(), newInterval);
    }
};