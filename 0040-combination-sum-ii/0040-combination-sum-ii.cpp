class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        findCombinations(0, target, candidates, ds, ans);
        return ans;
    }
    void findCombinations(int i, int target, vector<int>& candidates,
                          vector<int>& ds, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        if (i == candidates.size() || candidates[i] > target) {
            return;
        }
        ds.push_back(candidates[i]);
        findCombinations(i + 1, target - candidates[i], candidates, ds, ans);
        ds.pop_back();
        while (i + 1 < candidates.size() &&
               candidates[i + 1] == candidates[i]) {
            i++;
        }
        findCombinations(i + 1, target, candidates, ds, ans);
    }
};