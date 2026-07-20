class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int mid) {
        int cnt = 0;
        int bouq = 0;
        for (int day : bloomDay) {
            if (day <= mid) {
                cnt++;
            } else {
                cnt = 0;
            }
            if (cnt == k) {
                bouq++;
                cnt = 0;
            }
            if (bouq == m) {
                return true;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < (long long)m * k)
            return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, m, k, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};