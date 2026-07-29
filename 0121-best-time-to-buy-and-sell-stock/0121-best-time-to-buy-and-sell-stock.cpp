class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int buy = prices[0];
        for (int sell : prices) {
            if (sell - buy > 0) {
                maxP = max(maxP, sell - buy);
            } else {
                buy = sell;
            }
        }
        return maxP;
    }
};