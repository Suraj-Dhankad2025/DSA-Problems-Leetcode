class Solution {
public:
    int find(vector<int>&a,int i, int j,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int one = a[i] + min(find(a,i+1, j-1,dp), find(a, i+2,j,dp));
        int two = a[j] + min(find(a,i+1,j-1,dp), find(a,i,j-2,dp));
        return dp[i][j] = max(one, two);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int p1=0;
        int sum=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        vector<vector<int>>dp(25,vector<int>(25,0));
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<n; j++){
                if(i>j)continue;
                int one = nums[i] + min(i+1>j-1?0:dp[i+1][j-1], i+2>j?0:dp[i+2][j]);
                int two = nums[j] + min(i>j-2?0:dp[i][j-2], i+1>j-1?0:dp[i+1][j-1]);
                dp[i][j] = max(one, two);
            }
        }
        p1 = dp[0][n-1];
        if(p1>=(sum-p1))return true;
        else return false;
    }
};