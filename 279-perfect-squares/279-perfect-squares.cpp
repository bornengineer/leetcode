class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n ; i++){
            for(int k = 1; i - k*k >= 0 ; k++){
                if(dp[i - k*k] >= 0){
                    dp[i] = min(dp[i], (1 + dp[i - k*k]));
                }
            }
        }
        return dp[n];
    }
};