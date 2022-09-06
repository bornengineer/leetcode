class Solution {
public:
    bool divisorGame(int n) {
        // if n is odd return false else return true;
        // return n % 2 == 0;
        
        if(n == 1)return false;
        int *dp = new int[n+1];
        dp[1] = 0;
        dp[2] = 1;
        for(int i = 3; i<=n; i++){
            dp[i] = dp[i-2];
        }
        return dp[n]==0 ? false : true;
    }
};