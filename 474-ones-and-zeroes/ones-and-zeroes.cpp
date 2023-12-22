class Solution {
public:
    int find(int i,vector<pair<int, int>>&v, int m, int n, vector<vector<vector<int>>>&dp){
        if(i>=v.size()){
            return 0;
        }
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        int take = 0;
        int z = v[i].first;
        int o = v[i].second;
        if(m-z>=0 && n-o>=0){
            take = 1+find(i+1, v, m-z, n-o,dp);
        }
        int notTake = find(i+1, v, m, n,dp);
        return dp[i][m][n] = max(take, notTake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        string s="";
        vector<pair<int, int>>v;
        for(int i=0; i<strs.size(); i++){
            int z=0,o=0;
            for(auto it:strs[i]){
                if(it=='1'){
                    o++;
                }
                else{
                    z++;
                }
            }
            v.push_back({z,o});
        }
        vector<vector<vector<int>>>dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return find(0,v,m,n,dp);
    }
};