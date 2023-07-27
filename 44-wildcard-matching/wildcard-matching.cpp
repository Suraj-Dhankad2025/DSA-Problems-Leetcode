class Solution {
public:
bool find(int i, int j, string &s, string &t, vector<vector<int>>&dp){
    if(i==0 && j==0)return true;
    if(i==0 && j>0)return false;
    if(j==0 && i>0){
        for(int ii = i; ii>0; ii--){
            if(s[ii-1]!='*')return false;
        }
        return true;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i-1]==t[j-1] || s[i-1]=='?'){
        return dp[i][j] = find(i-1, j-1, s, t, dp);
    }
    else{
        if(s[i-1]=='*'){
            return dp[i][j] = find(i-1, j, s, t, dp) || find(i,j-1, s, t, dp);
        }
        else return false;
    }
    return false;
}
    bool isMatch(string s, string p) {
        int x = p.size();
        int y = s.size();
        vector<vector<int>>dp(x+1, vector<int>(y+1,-1));
        return find(x, y, p, s, dp);
    }
};