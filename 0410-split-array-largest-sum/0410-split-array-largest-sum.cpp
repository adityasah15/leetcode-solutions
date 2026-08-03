class Solution {
public:
    bool possible(vector<int>& nums, int k, int maxpgs) {
        int parts = 1;
        int totalpgs = 0;
        for (int pgs : nums) {
            if (totalpgs + pgs <= maxpgs) {
                totalpgs += pgs;
            } else {
                parts++;
                totalpgs = pgs;
            }
            if (parts > k)
                return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(nums, k, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};