class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto [num, freq] : mpp) { // [num, freq]
            bucket[freq].push_back(num);
        }
        vector<int> ans;
        for (int i = bucket.size() - 1; i > 0; i--) {
            if (k == 0)
                break;
            if (!bucket[i].empty()) {
                for (int n : bucket[i]) {
                    ans.push_back(n);
                    k--;
                }
            }
        }
        return ans;
    }
};