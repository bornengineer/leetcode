class Solution {
public:
    int rec(int idx, vector<int> &nums, int n, vector<int> &dp){
        if(idx >= n)return 0;
        
        if(dp[idx] != -1)return dp[idx];
        
        int ans = max(0 + rec(idx+1, nums, n, dp), nums[idx] + rec(idx+2, nums, n, dp));
        
        return dp[idx] = ans;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        
        vector<int> dp1(n, -1);
        // including first & excluding last element
        int ans1 = rec(0, nums, n-1, dp1);
        
        vector<int> dp2(n, -1);
        // excluding first & including last element
        int ans2 = rec(1, nums, n, dp2);
        
        return max(ans1, ans2);
    }
};