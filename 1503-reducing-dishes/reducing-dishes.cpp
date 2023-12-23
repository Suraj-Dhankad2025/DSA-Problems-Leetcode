class Solution {
public:
    int find(vector<int>&sat, int i, int t, vector<vector<int>>&dp){
        if(i==sat.size())return 0;
        if(dp[i][t]!=-1)return dp[i][t];
        int inc = sat[i]*t + find(sat, i+1, t+1,dp);
        int exc = find(sat, i+1, t,dp);
        return dp[i][t] = max(inc, exc);
    }
    int maxSatisfaction(vector<int>& sat) {
        vector<vector<int>>dp(sat.size()+1, vector<int>(sat.size()+1, -1));
        sort(sat.begin(), sat.end());
        return find(sat, 0, 1, dp);
    }
};