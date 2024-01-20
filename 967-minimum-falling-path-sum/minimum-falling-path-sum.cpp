class Solution {
public:
    // int find(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    //     if(j<0 || j>= matrix.size()){
    //         return 1e9;
    //     }
    //     if (i == 0) {
    //         return matrix[i][j];
    //     }
    //     if (dp[i][j] != -1) return dp[i][j];
    //     int ans = INT_MAX;
    //     int a = matrix[i][j] + find(i-1, j-1, matrix, dp);
    //     int b = matrix[i][j] + find(i-1, j+1, matrix, dp);
    //     int c = matrix[i][j] + find(i-1, j, matrix, dp);        
    //     ans = min(a, min(b,c));    
    //     return dp[i][j] = ans;
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // int ans = INT_MAX;
        // for (int i = 0; i < n; i++) {
        //     ans = min(ans, find(n-1, i, matrix, dp));
        // }
        int n = matrix.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int j=0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int a = matrix[i][j] + dp[i-1][j]; 
                int b = matrix[i][j];
                if(j-1>=0){
                    b+=dp[i-1][j-1];
                }
                else{
                    b+=1e9;
                }
                int c = matrix[i][j];
                if(j+1<n){
                    c+=dp[i-1][j+1];
                }
                else{
                    c+=1e9;
                }
                dp[i][j] = min(a, min(b,c));    
            }
        }
        int res = dp[n-1][0];
        for(int i=1; i<n; i++){
            res = min(res, dp[n-1][i]);
        }
        return res;
    }
};