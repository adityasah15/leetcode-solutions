class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        int minSum = 0;
        for (int i = 1; i <= k; i++) {
            minSum += i;
        }
        if (n < minSum || n > 45)
            return ans;
        solve(1, n, k, ds, ans);
        return ans;
    }
    void solve(int i, int n, int k, vector<int>& ds, vector<vector<int>>& ans) {
        if (n == 0 && k == 0) {
            ans.push_back(ds);
            return;
        }
        if (i > n || i > 9 || k == 0) {
            return;
        }
        ds.push_back(i);
        solve(i + 1, n - i, k - 1, ds, ans);
        ds.pop_back();
        solve(i + 1, n, k, ds, ans);
    }
};