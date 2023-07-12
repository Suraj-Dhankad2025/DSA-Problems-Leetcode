class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1e9+7;
        vector<vector<long long int>>dp(5, vector<long long int>(n+1,0));
        dp[0][1] = 1;
        dp[1][1] = 1;
        dp[2][1] = 1;
        dp[3][1] = 1;
        dp[4][1] = 1;
        int a=0,e=1,i=2,o=3,u=4;
        for(int j=2; j<=n; j++){
            dp[a][j] = (dp[e][j-1] + dp[u][j-1] + dp[i][j-1])%mod;
            dp[e][j] = (dp[a][j-1] + dp[i][j-1])%mod;
            dp[i][j] = (dp[e][j-1] + dp[o][j-1])%mod;
            dp[o][j] = (dp[i][j-1])%mod;
            dp[u][j] = (dp[i][j-1] + dp[o][j-1])%mod;
        }
        int ans = 0;
        for(int i=0;i<5;i++){
            ans=(ans+dp[i][n])%mod;
        }
        return ans%mod;
    }
};