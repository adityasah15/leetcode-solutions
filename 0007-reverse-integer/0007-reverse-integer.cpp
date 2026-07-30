class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN)
            return 0;
        bool neg = false;
        if (x < 0) {
            neg = true;
            x = -1 * x;
        }
        int ans = 0;
        while (x > 0) {
            int last = x % 10;
            if (ans <= INT_MAX / 10) {
                ans = ans * 10 + last;
            } else
                return 0;
            x = x / 10;
        }
        if (neg)
            ans = -1 * ans;
        return ans;
    }
};