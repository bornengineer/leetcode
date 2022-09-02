class Solution {
public:   
    //Recursive TLE
//     int rec(int n){
//         if(n <= 3)return n;

//         int ans = INT_MAX-1;
//         for(int i = 1; i*i <= n; i++){
//             ans = min(ans, 1 + rec(n - i*i));
//         }
//         return ans;
//     }    
    
//     int numSquares(int n) {
//         return rec(n);
//     }
    
    
    // Memoization
//     int solve(int n, vector<int>& memo){
//         if(n <= 3)return n;

//         if(memo[n])return memo[n];
        
//         int ans = INT_MAX-1;
//         for(int i = 1; i*i <= n; i++){
//             ans = min(ans, 1 + solve(n - i*i , memo));
//         }
        
//         memo[n] = ans;
//         return memo[n];
//     }  
    
//     int numSquares(int n) {
//         vector<int> memo(n+1);
//         return solve(n, memo);
//     }
    
    
    //Bottom up DP
//     int numSquares(int n) {
//         vector<int> dp(n+1, INT_MAX);
//         dp[0] = 0;
//         dp[1] = 1;
//         for(int i = 2; i <= n ; i++){
//             for(int k = 1; i - k*k >= 0 ; k++){
//                 if(dp[i - k*k] >= 0){
//                     dp[i] = min(dp[i], (1 + dp[i - k*k]));
//                 }
//             }
//         }
//         return dp[n];
//     }
    
    // Legendre's 3 square theorem TC - O(sqrt(n))
    int numSquares(int n) { // our ans will range form 1-4
        
        if(ceil(sqrt(n) == floor(sqrt(n))))return 1; // if n's a perfect square
        
        while(n%4 == 0)n = n/4; // checking 4a(8b+7)
        if(n % 8 == 7)return 4;
        
        // checking if there is a break point of 2 square nums e.g. 13 = 2^2 + 3^2
        for(int i = 1; i*i <= n; i++){ 
            int base = sqrt(n-i*i);
            if(base * base == (n - i*i))return 2;
        }
        
        // if all the cases aren't true then the ans will be 2
        // cause by lagranges 4 square theorem - every natural number 
        // can be represented by sum of 4 integer squares
        return 3;
    }
};