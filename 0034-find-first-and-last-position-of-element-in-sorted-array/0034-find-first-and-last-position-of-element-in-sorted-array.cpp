class Solution {
public:
    int lowerbound(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    int upperbound(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerbound(nums, target);
        if (first == nums.size() || nums[first] != target) {
            return {-1, -1};
        }
        return {first, upperbound(nums, target) - 1};
    }
};