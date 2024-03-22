class Solution {
public:
    int cost(int i, int j, string &s){
        if(i>=j){
            return 0;
        }
        int ans = cost(i+1, j-1, s);
        if(s[i]!=s[j])ans++;
        return ans;
    }
    int find(int i, int j, string &s, vector<vector<int>>&dp){
        if(j==0 && i!=-1){
            return 1e9;
        }
        if(i<0){
            if(j==0){
                return 0;
            }
            return 1e9;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = 1e9;
        for(int x=i; x>=0; x--){
            ans = min(ans, find(x-1, j-1, s, dp) + cost(x,i, s));
        }
        return dp[i][j] = ans;
    }
    int palindromePartition(string s, int k) {
        vector<vector<int>>dp(s.size()+1, vector<int>(k+1, -1));
        return find(s.length()-1, k, s, dp);
    }
};