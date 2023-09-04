class Solution {
public:
    int findLongestChain(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        // return find(0,pairs);
        int n = a.size();
        int ans=1;
        vector<int>dp(n, 1);
        for(int ind = 0; ind<n; ind++){
            for(int i = 0; i<ind; i++){
                if(a[i][1]<a[ind][0]){
                    dp[ind] = max(dp[ind], dp[i]+1);
                }
                ans = max(ans, dp[ind]);
            }
        }
        return ans;
    }
};