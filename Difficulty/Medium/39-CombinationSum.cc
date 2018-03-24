class Solution
{
  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ret;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        backtrack(ret, tmp, candidates, target, 0);
        return ret;
    }

    void backtrack(vector<vector<int>> &vec, vector<int> &tempVec, vector<int> &candidates, int remain, int start)
    {
        if (remain < 0)
            return;
        else if (remain == 0)
            vec.push_back(vector<int>(tempVec));
        else
        {
            for (int i = start; i < candidates.size(); ++i)
            {
                tempVec.push_back(candidates[i]);
                backtrack(vec, tempVec, candidates, remain - candidates[i], i);
                tempVec.pop_back();
            }
        }
    }
};