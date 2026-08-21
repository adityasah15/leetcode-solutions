class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        generate(0, INT_MIN, ds, ans, nums);
        return ans;
    }
    void generate(int start, int last, vector<int>& ds,
                  vector<vector<int>>& ans, vector<int>& nums) {
        if (ds.size() >= 2) {
            ans.push_back(ds);
        }
        unordered_set<int> st;
        for (int i = start; i < nums.size(); i++) {
            if (!st.count(nums[i]) && nums[i] >= last) {
                st.insert(nums[i]);
                ds.push_back(nums[i]);
                generate(i + 1, nums[i], ds, ans, nums);
                ds.pop_back();
            }
        }
    }
};