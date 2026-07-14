class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int currP = 0;
        int buy = prices[0];
        for (int sell : prices) {
            if (sell > buy) {
                currP = sell - buy;
                maxP = max(maxP, currP);
            } else {
                buy = sell;
            }
        }
        return maxP;
    }
};