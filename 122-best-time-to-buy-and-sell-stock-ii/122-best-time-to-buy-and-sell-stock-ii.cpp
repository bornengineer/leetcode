class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfTillNow = 0;
        int min = INT_MAX;
        int totalProfit = 0;
        for(int i = 0; i<prices.size(); i++){
            // if(prices[i] < min) min = prices[i];
            if(prices[i] > min){
                maxProfTillNow = prices[i] - min;
                totalProfit += maxProfTillNow;
                maxProfTillNow = 0;
            }
            min = prices[i];
        }
        return totalProfit;
    }
};