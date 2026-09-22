class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp = 0;
        int cp = prices[0];
        for (int sp : prices) {
            if (sp < cp) {
                cp = sp;
            } else {
                maxp = max(maxp, sp - cp);
            }
        }
        
        return maxp;
    }
};