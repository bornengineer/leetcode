class Solution {
public:
    
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n ; i++){
            int k = 1;
            while(i - k*k >= 0){
                if(dp[i - k*k] >= 0){
                    dp[i] = min(dp[i], (1 + dp[i - k*k]));
                    // break;
                }
                k++;
            }
        }
        return dp[n];
    }

};
//     void rec(int n, int *cnt){
//         for(int i = 1; i*i < n; i++){
//             if(n - i*i <= 0)return;
//             rec(n - i*i, cnt+1);
//         }
//     }    
    
//     int numSquares(int n) {
//         int ans = INT_MAX;
//         for(int i = 1; i*i < n; i++){
//             int cnt = 1;
//             rec(n - i*i, (&cnt)+1);
//             ans = min(ans, cnt);
//         }
//         return ans;
//     }