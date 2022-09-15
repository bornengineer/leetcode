class Solution {
public:
    int rec(int idx, vector<int>& nums, vector<int>& dp){
        if(idx >= nums.size())return 0;
        
        if(dp[idx] != -1)return dp[idx];
        
                            // pick                     // not pick
        int ans = max(nums[idx] + rec(idx+2, nums, dp), 0 + rec(idx+1, nums, dp));
        
        return dp[idx] = ans;
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return rec(0, nums, dp);
    }
};