class Solution {
public:
    int mod = 1e9+7;
    long long find(int i, int steps, int l, vector<vector<long long>>&dp){
        if(i<0 || i>=l || steps<0){
            return 0;
        }
        if(steps==0){
            if(i==0){
                return 1;
            } 
            return 0;
        }
        if(dp[i][steps]!=-1)return dp[i][steps];
        long long left = find(i-1, steps-1, l, dp)%mod;
        long long right = find(i+1, steps-1, l, dp)%mod;
        long long same = find(i, steps-1, l, dp)%mod;
    
        return dp[i][steps] = (left+right+same)%mod;
    }
    int numWays(int steps, int arrLen) {  
        int n=min(steps/2+1, arrLen);
        vector<vector<long long>>dp(n+1, vector<long long>(steps+1, -1));
        return static_cast<int>(find(0, steps, n, dp));
    }
};