class Solution {
public:
    int find(int i, int n, int k, vector<int>&arr, vector<int>&dp){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int len=0,sum=0,maxi=INT_MIN;
        int ans=0;
        for(int j=i; j<min(n, i+k); j++){
            len++;
            maxi = max(maxi, arr[j]);
            sum = maxi*len + find(j+1, n, k, arr, dp);
            ans = max(sum, ans);
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,-1);
        return find(0, n, k, arr, dp);
    }
};