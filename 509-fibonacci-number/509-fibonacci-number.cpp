class Solution {
public:
    // int fib(int n) {
    //     if(n == 0)return 0;
    //     else if(n == 1)return 1;
    //     else return fib(n-1) + fib(n-2);
    // }
    
    int fibHelper(int n, vector<int>& dp){
        if(n <= 1)return n;
        
        if(dp[n] != -1)return dp[n];
        
        dp[n] = fibHelper(n-1, dp) + fibHelper(n-2, dp);
        
        return dp[n];
    }
    
    int fib(int n){
        vector<int> dp(n+1, -1);
        return fibHelper(n, dp);
    }
};