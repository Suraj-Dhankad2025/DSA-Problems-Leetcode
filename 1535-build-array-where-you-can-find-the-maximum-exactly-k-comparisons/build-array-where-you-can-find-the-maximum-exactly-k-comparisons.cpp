class Solution {
public:
    int mod=1e9+7;
    int find(int i, int m, int k, int prev, vector<vector<vector<int>>>& dp) {
        if (i < 0) {
            if (k == 0) {
                return 1;
            }
            return 0;
        }
        if (k < 0) return 0;
        if (dp[i][k][prev] != -1) return dp[i][k][prev];
        int ans = 0;
        for (int x = 1; x <= m; x++) {
            if (x > prev) {
                ans += find(i - 1, m, k - 1, x, dp)%mod;
            } else {
                ans += find(i - 1, m, k, prev, dp)%mod;
            }
            ans = ans%mod;
        }
        return dp[i][k][prev] = ans%mod;
    }
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 1, -1)));
        return find(n - 1, m, k, 0, dp);
    }
};