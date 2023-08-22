// #include <bits/stdc++.h>
class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        unordered_map<int, vector<pair<int,int>>>m;
        for(int i=0; i<offers.size(); i++){
            m[offers[i][0]].push_back({offers[i][1], offers[i][2]});
        }
        vector<int>dp(n,0);
        for(int i=0; i<n; i++){
            for(auto it:m[i]){
                if(i==0){
                    dp[it.first] = max(dp[it.first], it.second);
                }
                else{
                    dp[it.first] = max(dp[it.first], it.second+dp[i-1]);
                }
            }
            if(i>0){
                dp[i] = max(dp[i], dp[i-1]);
            }
        }
        return dp[n-1];
    }
};