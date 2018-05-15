class Solution
{
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int total = 0;
        int j = -1;
        for (int i = 0, sum = 0; i < gas.size(); i++)
        {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];

            if (sum < 0)
            {
                j = i;
                sum = 0;
            }
        }
        return total >= 0 ? j + 1 : -1; // total 表示gas之和与cost之和的差，如大于等于0，则一定有解
    }
};