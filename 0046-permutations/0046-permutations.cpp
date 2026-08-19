class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        unordered_set<int> st;
        int n = nums.size();
        solve(ds, nums, st, ans, n);
        return ans;
    }

    void solve(vector<int>& ds, vector<int>& nums, unordered_set<int>& st,
               vector<vector<int>>& ans, int n) {
        if (ds.size() == n) {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!st.count(nums[i])) {
                ds.push_back(nums[i]);
                st.insert(nums[i]);
                solve(ds, nums, st, ans, n);
                ds.pop_back();
                st.erase(nums[i]);
            }
        }
    }
};