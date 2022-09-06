class Solution {
public: 
    // dp solution    
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        
        // starting from 1 cause for 0 it's already 0
        for(int i = 1; i<= n ; i++){
            if(i%2 ==0){
                dp[i] = dp[i/2];
            }else{
                dp[i] = dp[i-1] + 1;   
            }
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