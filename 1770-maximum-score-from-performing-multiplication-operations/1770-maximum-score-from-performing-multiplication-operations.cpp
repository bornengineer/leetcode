class Solution {
public:
    int rec(int s, int idx, int m, vector<int> &nums, vector<int> &mult, vector<vector<int>> &dp){
        int e = nums.size() - 1 - (idx - s);
        
        if(dp[idx][s] != INT_MIN)return dp[idx][s];
        
        if(idx == m)return 0;
        
        
        int start = (mult[idx] * nums[s]) + rec(s+1, idx+1, m, nums, mult, dp);
                     
        int end = (mult[idx] * nums[e]) + rec(s, idx+1, m, nums, mult, dp);
        
        int ans = max(start, end);
        
        return dp[idx][s] = ans;                     
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        
        vector<vector<int>> dp(m+1, vector<int>(m+1,INT_MIN));
        
        return rec(0, 0, m, nums, multipliers, dp);
    }
};