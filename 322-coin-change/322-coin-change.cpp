// Memoization
/*class Solution {
public:
    int rec(int idx, vector<int> &coins, int amount, vector<vector<int>> &dp){
        if(idx == 0){
            if(amount % coins[0] == 0)return amount / coins[0];
            else return 1e9;
        }
        
        if(dp[idx][amount] != -1)return dp[idx][amount];
        
        int notTake = 0 + rec(idx-1, coins, amount, dp);
        
        int take = INT_MAX;
        if(coins[idx] <= amount){
            take = 1 + rec(idx, coins, amount-coins[idx], dp);
        }
        
        return dp[idx][amount] = min(take, notTake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // taking amount into consideration cause we have to tacke amount = 0 also
        vector<vector<int>> dp(n,vector<int>(amount+1, -1));
        int ans = rec(n-1, coins, amount, dp);
        if(ans >= 1e9)return -1;
        else return ans;
    }
};*/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // taking amount into consideration cause we have to tacke amount = 0 also
        vector<vector<int>> dp(n,vector<int>(amount+1, 0));
        
        // base case
        for(int T = 0; T<=amount ; T++){
            if(T % coins[0] == 0)dp[0][T] = T / coins[0];
            else dp[0][T] = 1e9;
        }
        
        for(int idx = 1; idx<n; idx++){
            for(int T = 0; T<=amount; T++){
                // copy the recurrence & convert to dp
                int notTake = 0 + dp[idx-1][T];
        
                int take = INT_MAX;
                if(coins[idx] <= T){
                    take = 1 + dp[idx][T-coins[idx]];
                }

                dp[idx][T] = min(take, notTake);
            }
        }
        
        int ans = dp[n-1][amount];
        if(ans >= 1e9)return -1;
        else return ans;
    }
};


// kind of Greedy approach but it failed for - [186,419,83,408] 6249 & [9,6,5,1] 11
/*        int cnt = 0;
        int i = coins.size()-1;
        sort(coins.begin(), coins.end());
        
        while(amount != 0 && i >= 0){
            if(amount >= coins[i]){
                amount -= coins[i];
                cnt++;
            }
            else i--;
        }
        
        if(amount == 0)return cnt;
        else return -1;*/