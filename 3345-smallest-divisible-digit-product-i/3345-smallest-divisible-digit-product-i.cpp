class Solution {
public:
    bool possible(int num, int t) {
        int product = 1;
        while (num) {
            product *= (num % 10);
            num /= 10;
        }
        return product % t == 0;
    }
    int smallestNumber(int n, int t) {
        int num = n;
        while (!possible(num, t)) {
            num++;
        }
        return num;
    }
};