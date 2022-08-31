class Solution {
public:
    // Recursive approach but it will give TLE (it will accept till n = 41)
    // int climbStairs(int n) {
    // if(n<0)return 0;
    // if(n==0)return 1;
		    
    // return climbStairs(n-1)+climbStairs(n-2);
    // }
    
    
    // using memoezation TC - O(N)
    int helper(int n , vector<int>& memo){
        if(n < 0)return 0; 
        if(n == 0)return 1;
        if(memo[n])return memo[n];
        memo[n] = helper(n-1, memo) + helper(n-2, memo);
        return memo[n];       
    }
    
    int climbStairs(int n) {
        vector<int> memo(n+1);
        return helper(n, memo);
    }
};