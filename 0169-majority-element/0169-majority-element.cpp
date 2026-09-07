class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m = 0;
        int cnt = 0;
        for (int num : nums) {
            if (cnt == 0) {
                m = num;
            }
            if (num == m) {
                cnt++;
            }else{
                cnt--;
            }
        }
        return m;
    }
};