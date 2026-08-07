class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int toswap = -1;
        int n = nums.size();
        for(int i = n-1; i >= 1; i--){
            if(nums[i-1] >= nums[i]){
                continue;
            }
            toswap = i - 1;
            break;
        }
        if(toswap == -1){
           return reverse (nums.begin(), nums.end());
        }
        for (int i = n-1; i > toswap; i--){
            if(nums[i] > nums[toswap]){
                swap(nums[i], nums[toswap]);
                reverse (nums.begin() + toswap + 1, nums.end());
                break;
            }
        }
        
    }
};