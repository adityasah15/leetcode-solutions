class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int last3 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int first2last1 = nums[0] * nums[1] * nums[n - 1];
        int maxp = max(last3, first2last1);
        return maxp;
    }
};