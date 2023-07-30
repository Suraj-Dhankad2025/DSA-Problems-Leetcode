class Solution {
public:
    // int find(int i, int j, string s, vector<vector<int>>&dp){
    //     if(i==j){
    //         return 1;
    //     }
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int mini = INT_MAX;
    //     for(int k=i; k<j; k++){
    //         mini = min(mini, find(i, k, s, dp)+find(k+1,j,s, dp));
    //     }
    //     return dp[i][j] = (s[i]==s[j])?mini-1:mini;
    // }
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        
        for(int i=n-1; i>=0; i--){
            dp[i][i] = 1;
            for(int j=i+1; j<n; j++){
                int mini = INT_MAX;
                for(int k=i; k<j; k++){
                    mini = min(mini, dp[i][k] + dp[k+1][j]);
                }
                dp[i][j] = (s[i]==s[j])?mini-1:mini;
            }
        }
        return dp[0][n-1];
    }
};