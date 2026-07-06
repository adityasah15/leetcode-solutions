class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cp = prices[0];
        int sp;
        int tp = 0;
        for (int i = 1; i < prices.size(); i++) {
            sp = prices[i];
            if (sp - cp < 0) {
                cp = sp;
            } else if (sp - cp > 0) {
                tp = max(tp, sp - cp);
            }
        }
        return tp;
    }
};