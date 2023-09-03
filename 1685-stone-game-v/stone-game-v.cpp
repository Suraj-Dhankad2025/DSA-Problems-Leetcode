class Solution {
public:
    int find(int s, int e, vector<int>& v, vector<vector<int>>&dp){
        if(s>=e){
            return 0;
        }
        if(dp[s][e]!=-1)return dp[s][e];
        int sum=0;
        for(int i=s; i<=e; i++){
            sum+=v[i];
        }
        int left=0;
        int right=0;
        int ans=0;
        for(int i=s; i<e; i++){
            left+=v[i];
            right = sum - left;
            if(left<right){
                ans = max(ans, left + find(s, i, v, dp));
            }
            else if(left==right){
                ans = max(ans, left + max(find(s, i, v, dp), find(i+1, e, v, dp)));
            }
            else if(right<left){
                ans = max(ans, right + find(i+1, e, v, dp));
            }
        }
        return dp[s][e] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return find(0, n-1, stoneValue, dp);
    }
};