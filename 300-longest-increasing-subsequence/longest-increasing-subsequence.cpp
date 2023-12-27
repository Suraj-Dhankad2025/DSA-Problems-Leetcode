class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans=0,n=nums.size();
        vector<int> dp;
        for(auto i:nums) {
            int pos=lower_bound(dp.begin(),dp.end(),i)-dp.begin();
            if(pos==dp.size()) {
                dp.push_back(i);
            }
            else {
                dp[pos] = i;
            }
            ans = max(ans,pos+1);
        }
        return ans;
    }
};