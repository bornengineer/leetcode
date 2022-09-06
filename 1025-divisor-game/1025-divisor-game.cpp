class Solution {
public:
    bool divisorGame(int n) {
        int *dp = new int[n+1];
        for(int i = 1; i<=n; i++){
            if(i % 2 == 0)dp[i] = 1;
            else dp[i] = 0;
        }
        return dp[n]==0 ? false : true;
    }
};