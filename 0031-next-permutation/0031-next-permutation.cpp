class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int toswap = -1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i > 0 && nums[i] > nums[i - 1]) {
                toswap = i - 1;
                break;
            }
        }
        if (toswap == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = nums.size() - 1; i > toswap; i--) {
            if (nums[i] > nums[toswap]) {
                swap(nums[i], nums[toswap]);
                reverse(nums.begin() + toswap + 1, nums.end());
                return;
            }
        }
    }
};

// 1 2 3 8 4 2 --> 1 2 4 2 3 8