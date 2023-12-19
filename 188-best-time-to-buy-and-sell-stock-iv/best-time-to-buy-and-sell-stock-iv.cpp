class Solution {
public:
    int find(int i, int buy, int k, vector<int>&prices, vector<vector<vector<int>>>&dp){
        if(i==prices.size() || k==0){
            return 0;
        }
        if(dp[i][buy][k]!=-1)return dp[i][buy][k];
        int profit = 0;
        if(buy){
            int buy = -prices[i] + find(i+1,0,k,prices,dp);
            int notBuy = find(i+1,1,k,prices,dp);
            profit = max(buy,notBuy);
        }
        else{
            int sell = prices[i] + find(i+1,1,k-1,prices,dp);
            int notSell = find(i+1,0,k,prices,dp);
            profit = max(sell, notSell);
        }
        return dp[i][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& a) {
        int n = a.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(k+1,-1)));
        return find(0,1,k,a,dp);
    }
};