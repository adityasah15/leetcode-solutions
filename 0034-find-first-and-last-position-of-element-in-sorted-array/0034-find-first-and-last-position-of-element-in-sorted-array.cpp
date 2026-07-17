class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] >= target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    int upperBound(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] > target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);
        if (first == nums.size() || nums[first] != target) {
            return {-1, -1};
        }
        return {first, upperBound(nums, target) - 1};
    }
};