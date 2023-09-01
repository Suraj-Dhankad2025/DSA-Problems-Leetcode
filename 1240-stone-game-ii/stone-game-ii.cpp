class Solution {
public:
    int find(int ind, int m, vector<int>&p, vector<vector<int>>&dp){
        if(ind>=p.size()){
            return 0;
        }
        if(dp[ind][m]!=-1)return dp[ind][m];
        int ans=INT_MIN;
        int total=0;
        for(int i=0; i<2*m; i++){
            if(ind+i<p.size()){
                total+=p[i+ind];
            }
            ans = max(ans, total - find(ind+i+1,max(m, i+1), p, dp));
        }
        return dp[ind][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>>dp(piles.size()+1,vector<int>(piles.size()+1,-1));
        int ans = find(0, 1, piles,dp);
        int sum = accumulate(piles.begin(), piles.end(), 0);
        return (sum + ans)/2;
    }
};