class Solution {
public:
    int find(vector<vector<int>>& grid, int i, int j1, int j2, vector<vector<vector<int>>>&dp){
        if(i>=grid.size() || j1>=grid[0].size() || j2>=grid[0].size() || j1<0 || j2<0){
            return -1e9;
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        if(i==grid.size()-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        int ans = 0;
        if(j1!=j2){
            ans = ans + grid[i][j1] + grid[i][j2];
            int res=INT_MIN;
            for(int k=-1; k<=1; k++){
                for(int l=-1; l<=1; l++){
                    res = max(res, find(grid, i+1, j1+k, j2+l, dp));
                }
            }
            ans += res;
        }
        else{
            ans = ans + grid[i][j2];
            int res=INT_MIN;
            for(int k=-1; k<=1; k++){
                for(int l=-1; l<=1; l++){
                    res = max(res, find(grid, i+1, j1+k, j2+l, dp));
                }
            }
            ans += res;
        }
        return dp[i][j1][j2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>>dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return find(grid, 0, 0, grid[0].size()-1, dp);
    }
};