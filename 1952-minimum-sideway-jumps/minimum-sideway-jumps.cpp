class Solution {
public:
    int find(int lane, int i, vector<int>& obs, vector<vector<int>>&dp){
        if(i == obs.size()-1){
            return 0;
        }
        if(dp[i][lane]!=-1)return dp[i][lane];
        if(obs[i+1] != lane){
            return dp[i][lane] = find(lane, i+1, obs, dp);
        }
        else{
            int ans = INT_MAX;
            for(int j=1;j<=3;j++){
                if(lane != j && obs[i] != j){
                    ans = min(ans,1 + find(j, i, obs, dp));
                }
            }
            return dp[i][lane] = ans;
        }
    }
    int minSideJumps(vector<int>& obs) {
        vector<vector<int>>dp(obs.size()+1, vector<int>(4, -1));
        return find(2, 0, obs, dp);
    }
};