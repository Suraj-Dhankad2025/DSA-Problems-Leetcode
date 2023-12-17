class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& a) {
    //     sort(envelopes.begin(), envelopes.end());
    //     vector<int>dp(envelopes.size(), 1);
    //     int ans = 1;
    //     for(int i=0; i<envelopes.size(); i++){
    //         for(int j=0; j<i; j++){
    //             if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1]){
    //                 dp[i] = max(dp[i], dp[j]+1);
    //             }
    //         }
    //         ans = max(ans, dp[i]);
    //     }
    //     return ans;
        sort(a.begin(), a.end(), cmp);
        vector<int>dp;
        for(int i=0; i<a.size(); i++){
            int ele = a[i][1];
            int idx = lower_bound(dp.begin(), dp.end(), ele) - dp.begin();
            if(idx>=dp.size()){
                dp.push_back(ele);
            }
            else{
                dp[idx] = ele;
            }
        }
        return dp.size();
    }
};