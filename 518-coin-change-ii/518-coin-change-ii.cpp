/*class Solution {
public:
    int rec(int idx, int sum, int amount, vector<int> &coins){
        if(idx >= coins.size()){
            if(sum != 0){
                return (amount % sum == 0);
            }
        }

        // cout<<sum<<" "<<*cnt<<"\n";
        //pick
        int pick = 0;
        if(sum < amount){
            sum += coins[idx];
            pick = rec(idx, sum, amount, coins);
            sum -= coins[idx];
        }
            
        // not pick
        int notPick = rec(idx+1, sum, amount, coins);   
        
        return pick + notPick;
    }
    
    int change(int amount, vector<int>& coins) {
        // vector<int> dp(n, -1);
        return rec(0, 0, amount, coins);
    }
};*/

class Solution {
public:
    int rec(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(dp[idx][amount] != -1)return dp[idx][amount];
        
        if(idx <= 0){
            return(amount % coins[0] == 0);
        }
        // not pick
        int notPick = rec(idx-1, amount, coins, dp);   
        
        //pick
        int pick = 0;
        if(coins[idx] <= amount){
            pick = rec(idx, amount - coins[idx], coins, dp);
        }
            
        return dp[idx][amount] = pick + notPick;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // making vector of amount+1 size cause it's value can be 0 also
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        return rec(n-1, amount, coins, dp);
    }
};