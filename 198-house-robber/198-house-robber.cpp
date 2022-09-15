// Memoization
// class Solution {
// public:
//     int rec(int idx, vector<int>& nums, vector<int>& dp){
//         if(idx >= nums.size())return 0;
        
//         if(dp[idx] != -1)return dp[idx];
        
//                             // pick                     // not pick
//         int ans = max(nums[idx] + rec(idx+2, nums, dp), 0 + rec(idx+1, nums, dp));
        
//         return dp[idx] = ans;
//     }
    
//     int rob(vector<int>& nums) {
//         vector<int> dp(nums.size(), -1);
//         return rec(0, nums, dp);
//     }
// };

class Solution {
public:    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        
        for(int i = 2; i<n; i++){
            dp[i] = max(nums[i] + dp[i-2], 0 + dp[i-1]);
        }
        
        return dp[n-1];
    }
};