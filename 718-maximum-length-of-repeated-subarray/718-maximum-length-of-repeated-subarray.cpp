class Solution {   
    public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m = nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1, 0));
        int ans = 0;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                // if the nums match just put 1 + last diagonal element to dp[i][j]
                if(nums1[i-1] == nums2[j-1])dp[i][j] = 1 + dp[i-1][j-1];
                // and maintain max ans till now
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};


// not my code
/*class Solution {
public:
    int f(vector<int>& nums1, vector<int>& nums2,int n,int m,vector<vector<int>> &dp){
        if(n==-1 || m==-1) return 0;

        if(dp[n][m]!=-1) return dp[n][m];

        int ans=0;

        ans=f(nums1,nums2,n-1,m,dp);
        ans=f(nums1,nums2,n,m-1,dp);

        if(nums1[n]==nums2[m]){
            ans=f(nums1,nums2,n-1,m-1,dp)+1;
        }else{
            ans=0;
        }
        return dp[n][m]=ans;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        f(nums1,nums2,n-1,m-1,dp);
        int res=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                res=max(res,dp[i][j]);
            }
        }
        return res;
    }
};*/