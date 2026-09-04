class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates, ds, ans);
        return ans;
    }
    void solve(int i, int target, vector<int>& candidates, vector<int>& ds,
               vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        if (i == candidates.size()) {
            return;
        }
        if (candidates[i] > target)
            return;
        ds.push_back(candidates[i]);
        solve(i, target - candidates[i], candidates, ds, ans);
        ds.pop_back();
        solve(i + 1, target, candidates, ds, ans);
    }
};