class Solution {
public:
    bool find(int n, vector<int>&dp){
        if(n<=0){
            return 0;
        }
        if(dp[n]!=-1)return dp[n];
        for(int i=1; i*i<=n; i++){
            if(find(n - i*i, dp)==0){
                return dp[n] = 1;
            }
        }
        return dp[n] = 0;
    }
    bool winnerSquareGame(int n) {
        vector<int>dp(100001, -1);
        return find(n, dp);
    }
};