class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int toswap = -1;
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                toswap = i - 1;
                break;
            }
        }
        if (toswap == -1) {
            return reverse(nums.begin(), nums.end());
        }
        for (int i = nums.size() - 1; i > toswap; i--) {
            if (nums[i] > nums[toswap]) {
                swap(nums[toswap], nums[i]);
                break;
            }
        }
        reverse(nums.begin() + toswap + 1, nums.end());
    }
};