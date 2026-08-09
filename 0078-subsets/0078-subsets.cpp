class Solution {
public:
    void generate(int i, vector<int>& ds, vector<vector<int>>& ans, vector<int>& nums) {
        if (i >= nums.size()) {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        generate(i + 1, ds, ans, nums);
        ds.pop_back();
        generate(i + 1, ds, ans, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        generate(0, ds, ans, nums);
        return ans;
    }
};
