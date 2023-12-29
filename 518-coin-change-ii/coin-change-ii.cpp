class Solution {
public:
    int change(int amount, vector<int>& v) {
        int n = v.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, 0));
        dp[n][0] = 1;
        for(int i=1; i<=amount; i++){
            dp[n][i] = 0;
        }
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=amount; j++){
                int notTake = dp[i+1][j];
                int take = 0;
                if(v[i]<=j){
                    take = dp[i][j-v[i]];
                }
                dp[i][j] = take+notTake;
            }
        }
        return dp[0][amount];
    }
};