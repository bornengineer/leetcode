class Solution {
public: 
    // dp solution    
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        
        // starting from 1 cause for 0 it's already 0
        for(int i = 1; i<= n ; i++){
            // if(i%2 ==0){
            //     dp[i] = dp[i/2];
            // }else{
            //     dp[i] = dp[i-1] + 1;   
            // }
            
            // or 
            // above approach and below is same if we look them in detail
            // the i & 1 part will work for odd i's and won't work for even i's
            // while the dp[i>>1] will work for both
            // for eg: n = 7 dp[7 >> 1] == dp[3] while in above approach dp[7-1] = dp[6]
            // it is proven that every even i's set bits are equal to it half's set bits
            dp[i] = dp[i>>1] + (i & 1);
        }
        return dp;
    }
};

// class Solution {
// public: 
//     // recursive solution
//     int countSetBits(int i){
//         int cnt = 0;
//         while(i > 0){
//             cnt += i % 2;
//             i /= 2;
//         }
//         return cnt;
//     }
    
//     void helper(int n, vector<int>& ans){
//         if(n == 0){
//             ans.push_back(0);
//             return;
//         }
        
//         helper(n-1, ans);
        
//         ans.push_back(countSetBits(n));
//     }
    
//     vector<int> countBits(int n) {
//         vector<int> ans;
//         vector<int> memo(n+1);
//         helper(n, ans);
//         return ans;
//     }
// };


// iterative solution
/*class Solution {
public:
    int countSetBits(int i){
        int cnt = 0;
        
        while(i > 0){
            cnt += i % 2;
            i /= 2;
        }
        
        return cnt;
    }
    
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i = 0; i<=n; i++){
            int ones = countSetBits(i);
            ans.push_back(ones);
        }
        
        return ans;
    }
 };
 */