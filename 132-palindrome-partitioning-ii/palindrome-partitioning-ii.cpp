class Solution {
public:
    bool check(int i, int j, string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int find(int i, int n, string &s, vector<int>&dp){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int mini = INT_MAX;
        for(int j=i; j<n; j++){
            if(check(i, j, s)){
                int cost = 1 + find(j+1, n, s, dp);
                mini = min(mini, cost);
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n, -1);
        return find(0, n, s, dp)-1;
    }
};