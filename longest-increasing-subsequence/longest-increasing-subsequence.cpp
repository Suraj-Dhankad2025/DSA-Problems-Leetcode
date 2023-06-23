class Solution {
public:
    int solve(int i, int n,vector<int>&nums, int prev, vector<vector<int>>&dp){
        if(i==n){
            return 0;
        }
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int nt = 0 + solve(i+1, n,nums, prev, dp);
        int t=0;
        if(prev==-1 || nums[i]>nums[prev]){
            t = 1 + solve(i+1, n, nums, i, dp);
        }
        return dp[i][prev+1] = max(t,nt);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1,-1));
        return solve(0, n, nums, -1,dp);
        
    }
};