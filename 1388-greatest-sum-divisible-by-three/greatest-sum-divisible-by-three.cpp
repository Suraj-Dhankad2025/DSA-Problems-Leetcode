class Solution {
public:
    int find(int i, vector<int>&nums, int x, vector<vector<int>>&dp){
        if(i==nums.size()){
            if(x==0){
                return 0;
            }
            return -1e9;
        }
        if(dp[i][x]!=-1)return dp[i][x];
        int notTake = find(i+1, nums, (x)%3, dp);
        int take = nums[i] + find(i+1, nums, (x+nums[i])%3, dp);
        return dp[i][x] = max(take, notTake);
    }
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(), vector<int>(4, -1));
        return find(0, nums, 0, dp);
    }
};