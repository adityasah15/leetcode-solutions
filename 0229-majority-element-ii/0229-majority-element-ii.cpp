class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m1 = INT_MAX;
        int m2 = INT_MAX;
        int count1 = 0, count2 = 0;
        for (int num : nums) {
            if (num == m1) {
                count1++;
            } else if (num == m2) {
                count2++;
            } else if (count1 == 0) {
                m1 = num;
                count1++;
            } else if (count2 == 0) {
                m2 = num;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == m1) {
                count1++;
            } else if (num == m2) {
                count2++;
            }
        }
        int n = nums.size();
        vector<int> ans;
        if (count1 > n / 3) {
            ans.push_back(m1);
        }
        if (m1 != m2 && count2 > n / 3) {
            ans.push_back(m2);
        }
        return ans;
    }
};