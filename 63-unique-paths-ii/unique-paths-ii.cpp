class Solution {
public:
    int find(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i>n||j>m||i<0||j<0||grid[i][j]==1)return 0;
        if(i==n && j==m){
            return 1;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int down = find(i+1, j, n, m, grid, dp);
        int right = find(i, j+1, n, m, grid, dp);
        return dp[i][j] = down + right;        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int n = Grid.size();
        int m = Grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return find(0, 0, n-1, m-1, Grid, dp);
    }
};