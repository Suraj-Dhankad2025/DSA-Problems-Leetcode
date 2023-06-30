class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n,1);
        sort(nums.begin(), nums.end());
        int maxi = 1;
        int lastIndex = 0;
        for(int i=0;i<n; i++){
            hash[i] = i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                lastIndex = i;
            }  
        }
        vector<int>a;
        a.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex = hash[lastIndex];
            a.push_back(nums[lastIndex]);
        }
        return a;
    }
};