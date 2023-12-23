class Solution {
public:
    int find(string &s, string &t, int i, int j, vector<vector<int>>&dp){
        int cost = 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==s.size() || j==t.size()){
            for(int x=i; x<s.size(); x++){
                cost+=s[x];
            }
            for(int x=j; x<t.size(); x++){
                cost+=t[x];
            }
        }
        else if(s[i]==t[j]){
            cost = find(s,t,i+1, j+1, dp);
        }
        else{
            int c1 = s[i] + find(s, t, i+1, j, dp);
            int c2 = t[j] + find(s, t, i, j+1, dp);
            cost = min(c1, c2);
        }
        return dp[i][j] = cost;
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return find(s1,s2, 0, 0, dp);
    }
};