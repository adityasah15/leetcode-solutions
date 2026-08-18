class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, ds, ans, nums);
        return ans;
    }
    void findSubsets(int i, vector<int>& ds, vector<vector<int>>& ans, vector<int>& nums) {
        if (i == nums.size()) {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        findSubsets(i + 1, ds, ans, nums);
        ds.pop_back();
        while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
            i++;
        }
        findSubsets(i + 1, ds, ans, nums);
    }
};