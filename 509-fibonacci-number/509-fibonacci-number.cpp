class Solution {
public:
    // int fib(int n) {
    //     if(n == 0)return 0;
    //     else if(n == 1)return 1;
    //     else return fib(n-1) + fib(n-2);
    // }
    
//     int fibHelper(int n, vector<int>& dp){
//         if(n <= 1)return n;
        
//         if(dp[n] != -1)return dp[n];
        
//         dp[n] = fibHelper(n-1, dp) + fibHelper(n-2, dp);
        
//         return dp[n];
//     }
//     int fib(int n){
//         vector<int> dp(n+1, -1);
//         return fibHelper(n, dp);
//     }
    
//     int fib(int n){
//         if(n<2)return n;
        
//         vector<int> memo(n+1);
//         memo[0] = 0;
//         memo[1] = 1;
        
//         for(int i = 2; i<=n; i++){
//             memo[i] = memo[i-2] + memo[i-1];
//         }
        
//         return memo[n];
//     }
    
    int fib(int n){
        if(n<2)return n;
        int a = 0, b = 1, c = 0;
        for(int i = 1; i<n ; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};