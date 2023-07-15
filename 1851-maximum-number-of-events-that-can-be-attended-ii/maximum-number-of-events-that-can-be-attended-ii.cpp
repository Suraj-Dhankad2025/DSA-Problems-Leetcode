class Solution {
public:
    int find(int pos, int n, int k, vector<vector<int>>& events,
    vector<vector<int>>&dp){
        if(pos>=n || k==0){
            return 0;
        }
        if(dp[pos][k]!=-1)return dp[pos][k];
        int i;
        for(i=pos+1; i<n; i++){
            if(events[i][0]>events[pos][1]){
                break;
            }
        }
        return dp[pos][k] = 
        max(find(pos+1, n, k, events,dp), events[pos][2] + 
        find(i, n, k-1, events,dp));
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
        sort(events.begin(), events.end());
        return find(0, n, k, events,dp);
    }
};