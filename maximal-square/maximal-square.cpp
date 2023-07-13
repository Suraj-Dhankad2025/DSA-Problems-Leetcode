class Solution {
public:
    int find(int i, int j, int &maxi, vector<vector<char>>& matrix,             vector<vector<int>>&dp){
        if(i>=matrix.size() || j>=matrix[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int right = find(i, j+1, maxi, matrix, dp);
        int down = find(i+1, j, maxi, matrix, dp);
        int diagonal = find(i+1, j+1, maxi, matrix, dp);
        if(matrix[i][j]=='1'){
            dp[i][j] = 1 + min(down, min(right, diagonal));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j] = 0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n ,vector<int>(m,-1));
        int maxi = 0;
        find(0,0,maxi,matrix, dp);
        return maxi*maxi;
    }
};