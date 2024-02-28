class Solution {
public:
    int find(int lane, int i, vector<int>& obs,  vector<vector<int>>&dp){
        if(i>=obs.size()-1){
            return 0;
        }
        if(dp[i][lane]!=-1)return dp[i][lane];
        int ans = 1e9;
        if(obs[i]==lane)return ans;
        if(lane==2){
            if(obs[i+1]!=2){
                ans = min(ans, find(lane, i+1, obs, dp));
            }
            if(obs[i]!=1){
                ans = min(ans, 1 + find(1, i+1, obs, dp));
            }
            if(obs[i]!=3){
                ans = min(ans,1 + find(3, i+1, obs, dp));
            }
        }
        else if(lane==1){
            if(obs[i+1]!=1){
                ans = min(ans, find(lane, i+1, obs, dp));
            }
            if(obs[i]!=2){
                ans = min(ans,1 + find(2, i+1, obs, dp));
            }
            if(obs[i]!=3){
                ans = min(ans,1 + find(3, i+1, obs, dp));
            }
        }
        else if(lane==3){
            if(obs[i+1]!=3){
                ans = min(ans, find(lane, i+1, obs, dp));
            }
            if(obs[i]!=1){
                ans = min(ans,1 + find(1, i+1, obs, dp));
            }
            if(obs[i]!=2){
                ans = min(ans,1 + find(2, i+1, obs, dp));
            }
        }
        return dp[i][lane] = ans;
    }
    int minSideJumps(vector<int>& obs) {
        vector<vector<int>>dp(obs.size()+1, vector<int>(4, -1));
        return find(2, 0, obs, dp);
    }
};