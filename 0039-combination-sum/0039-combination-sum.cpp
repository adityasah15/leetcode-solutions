class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, target, ds, ans, candidates);
        return ans;
    }
    void solve(int i, int target, vector<int>& ds, vector<vector<int>>& ans,
               vector<int>& candidates) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        if (i == candidates.size()) {
            return;
        }
        if (candidates[i] <= target) {
            ds.push_back(candidates[i]);
            solve(i, target - candidates[i], ds, ans, candidates);
            ds.pop_back();
        }
        solve(i + 1, target, ds, ans, candidates);
    }
};