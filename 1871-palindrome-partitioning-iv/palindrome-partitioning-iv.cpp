class Solution {
public:
    bool check(string &s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--])return 0;
        }
        return 1;
    }
    bool find(int l, int r, string &s,int ans, vector<vector<int>>&dp){
        if(ans==2){
            return check(s, l, r);
        }
        if(dp[l][r]!=-1)return dp[l][r];
        for(int j=l; j<r; j++){
            if(check(s, l, j) && find(j+1, r, s, ans+1, dp)){
                return dp[l][r] = 1;
            }
        }
        return dp[l][r] = 0;
    }
    bool checkPartitioning(string s) {
        vector<vector<int>>dp(s.size(), vector<int>(s.size(), -1));
        return find(0, s.size()-1, s, 0, dp); 
    }
};