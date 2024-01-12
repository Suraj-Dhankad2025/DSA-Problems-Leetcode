class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        int f=0;
        for(int i=0; i<n; i++){
            f+=i*nums[i];
            sum+=nums[i];
        }
        vector<int>dp(n, -1);
        dp[0] = f;
        int ind=n-1;
        for(int i=1; i<n; i++){
            dp[i] = dp[i-1] + sum - n*nums[ind];
            ind--;
        }
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};