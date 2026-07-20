class Solution {
public:
    bool possible(vector<int>& piles, int h, int mid) {
        int totalhrs = 0;
        for (int pile : piles) {
            totalhrs += (pile + mid - 1) / mid;
            if (totalhrs > h)
                return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(piles, h, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};