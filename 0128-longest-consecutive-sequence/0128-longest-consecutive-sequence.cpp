class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int maxcount = 0;
        for (int num : seen) {
            int count = 0;
            if (seen.count(num - 1))
                continue;
            for (int i = 0; i < seen.size(); i++) {
                if (seen.count(num + i)) {
                    count++;
                } else {
                    break;
                }
            }
            maxcount = max(maxcount, count);
        }
        return maxcount;
    }
};