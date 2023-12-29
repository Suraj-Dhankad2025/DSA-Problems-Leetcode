class Solution {
public:
    int find(int ind, int amount, vector<int>&coins, vector<vector<int>>&dp){
        if(ind>=coins.size()){
            if(amount==0)return 1;
            return 0;
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int notTake = find(ind+1, amount, coins, dp);
        int take = 0;
        if(coins[ind]<=amount)take = find(ind, amount - coins[ind], coins, dp);
        return dp[ind][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));
        return find(0, amount, coins, dp);
    }
};