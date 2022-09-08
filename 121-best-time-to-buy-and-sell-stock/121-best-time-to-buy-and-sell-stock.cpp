class Solution {
public:
    int maxProfit(vector<int>& prices) {         
//         O(n) optimal
        // /*
        int min = prices[0];
        int maxProfit = 0;
        int n = prices.size();
        
        for(int i = 0 ; i < n ; i++){
            if(prices[i] < min){
                min = prices[i];
            }
            else{
                maxProfit = max(maxProfit, prices[i] - min);
            }
        }
        return maxProfit;
        // */
        
        
//         brute force
//         int maxProfit = 0 ;
//         int n = prices.size();

//         for(int i = 0; i < n ; i++ ){
//             for(int j = i+1 ; j < n ; j++){
//                 if(prices[j] > prices[i])
//                     maxProfit = max(maxProfit, prices[j] - prices[i]);
//             }
//         }
//         return maxProfit;    
    }
};
        
//         153 test cases passed but it is'nt the right approach
        // cause we can sell the stock going in past (08-02-2022)
//         int min = INT_MAX, mindex; 
//         for(int i = 0; i < prices.size(); i++){
//             if(prices[i] < min){
//             min = prices[i]; 
//             mindex = i;
//             } 
//         }
        
//         int max = INT_MIN;
//         for(int j = 0 ; j < prices.size(); j++){
//             if(j>mindex){
//                 if(prices[j] > max) 
//                 max = prices[j];
//             }
//         }
//         if(max<=0)return 0;
        
//         return max - min;