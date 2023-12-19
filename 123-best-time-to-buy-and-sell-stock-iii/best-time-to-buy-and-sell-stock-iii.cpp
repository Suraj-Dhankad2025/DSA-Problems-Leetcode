class Solution {
public:
    int find(int i, bool buy, int count, vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(i==prices.size() || count==2){
            return 0;
        }
        if(dp[i][buy][count]!=-1)return dp[i][buy][count];
        int profit = 0;
        if(buy){
            profit = max(-prices[i]+find(i+1,0,count,prices,dp), find(i+1,1,count,prices,dp));
        }
        else{
            profit = max(prices[i]+find(i+1,1,count+1,prices,dp),find(i+1,0,count,prices,dp));
        }
        return dp[i][buy][count] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(3,-1)));
        return find(0,1, 0, prices,dp);
    }
};