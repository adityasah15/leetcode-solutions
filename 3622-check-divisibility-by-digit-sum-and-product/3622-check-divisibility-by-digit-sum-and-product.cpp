class Solution {
public:
    bool checkDivisibility(int n) {
        int prod = 1;
        int sum = 0;
        int temp = n;
        while (n) {
            int last = n % 10;
            sum += last;
            prod *= last;
            n /= 10;
        }
        if (temp % (sum + prod) == 0) {
            return true;
        }
        return false;
    }
};