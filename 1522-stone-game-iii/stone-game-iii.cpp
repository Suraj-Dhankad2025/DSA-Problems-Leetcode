class Solution {
public:
    int find(vector<int>&s, int i, vector<int>&dp){
        if(i>=s.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MIN;
        if(i<s.size()){
            ans = max(ans, s[i] - find(s, i+1, dp));
        }
        if(i+1<s.size()){
            ans = max(ans, s[i] + s[i+1] - find(s, i+2, dp));
        }
        if(i+2<s.size()){
            ans = max(ans, s[i] + s[i+1] + s[i+2] - find(s, i+3, dp));
        }
        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(stoneValue.size(),-1);
        int alice = find(stoneValue, 0, dp);
        if(alice>0){
            return "Alice";
        }
        if(alice==0){
            return "Tie";
        }
        return "Bob";
    }
};