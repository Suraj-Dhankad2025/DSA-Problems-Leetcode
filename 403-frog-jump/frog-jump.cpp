class Solution {
public:
    bool find(int prev, int jump, vector<int>&stones, unordered_map<int,int>&m, vector<vector<int>>&dp){
        if(stones[prev] + jump==stones.back()){
            return true;
        }
        if(m.find(stones[prev] + jump)==m.end()){
            return false;
        }
        if(dp[prev][jump]!=-1)return dp[prev][jump];
        int ind = m[stones[prev] + jump];
        bool ans;
        ans = find(ind, jump+1, stones,m,dp);
        ans = ans||find(ind, jump, stones, m,dp);
        if(jump>1){
            ans = ans||find(ind, jump-1, stones, m,dp);
        }
        return dp[prev][jump] = ans;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int, int>m;
        vector<vector<int>>dp(stones.size(), vector<int>(stones.size(),-1));
        for(int i=0; i<stones.size(); i++){
            m[stones[i]] = i;
        }
        return find(0,1,stones,m,dp);
    }
};