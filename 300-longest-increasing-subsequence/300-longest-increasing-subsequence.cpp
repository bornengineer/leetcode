class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    //     int min = nums[0];
    //     int i = 0;
    //     for(; i<nums.size(); i++){
    //         if(nums[i] < min)min = nums[i];
    //         else if(nums[i] > min)break;
    //     }
    //     i--;
    //     int curr = min;
    //     int cnt = 1;z
    //     for(; i<nums.size(); i++){
    //         if(nums[i] > curr){
    //             curr = nums[i];
    //             cnt++;
    //         }
    //     }
    //     return cnt;
        
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        // we are checking for every position in nums and applying dp (bottom up)
        // by checking previous index's LIS
        for(int i = 1; i<n; i++){
            for(int j = i-1; j>=0; j--){
                
                // if(nums[j] >= nums[i])continue;
                // int possibleAns = dp[j] + 1;
                // if(possibleAns > dp[i]){
                //     dp[i] = possibleAns;
                //     ans = max(ans, dp[i]);
                // }
                
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};