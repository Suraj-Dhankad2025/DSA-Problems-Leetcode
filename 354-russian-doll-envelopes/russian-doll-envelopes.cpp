class Solution {
public:
    static bool cmp(vector<int>a, vector<int>b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(), e.end(), cmp);
        vector<int>dp;
        for(int i=0; i<e.size(); i++){
            int num = e[i][1];
            int ind = lower_bound(dp.begin(), dp.end(), num) -  dp.begin();
            if(ind>=dp.size()){
                dp.push_back(num);
            }
            else{
                dp[ind] = num;
            }
        }
        return dp.size();
    }
};