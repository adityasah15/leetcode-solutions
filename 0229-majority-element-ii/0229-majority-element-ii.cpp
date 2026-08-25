class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m1 = 0, m2 = 0, cnt1 = 0, cnt2 = 0;
        for (int num : nums) {
            if (cnt1 > 0 && num == m1) {
                cnt1++;
            } else if (cnt2 > 0 && num == m2) {
                cnt2++;
            } else if (cnt1 == 0) {
                m1 = num;
                cnt1++;
            } else if (cnt2 == 0) {
                m2 = num;
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for (int num : nums) {
            if (num == m1) {
                cnt1++;
            } else if (num == m2) {
                cnt2++;
            }
        }
        vector<int> ans;
        int n = nums.size();
        if (cnt1 > n / 3) {
            ans.push_back(m1);
        }
        if (cnt2 > n / 3) {
            ans.push_back(m2);
        }
        return ans;
    }
};