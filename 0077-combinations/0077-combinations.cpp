class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        generate(1, k, n, ds, ans);
        return ans;
    }
    void generate(int idx, int k, int& n, vector<int>& ds,
                  vector<vector<int>>& ans) {
        if (k == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = idx; i <= n; i++) {
            ds.push_back(i);
            generate(i + 1, k - 1, n, ds, ans);
            ds.pop_back();
        }
    }
};