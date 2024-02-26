class Solution {
public: 
    int longestArithSeqLength(vector<int>& nums) {
        if(nums.size()==2){
            return 2;
        }
        unordered_map<int,int>dp[nums.size()+1];
        int ans=0;
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                int dif = nums[i] - nums[j];
                int c = 1;
                if(dp[j].count(dif)){
                    c = dp[j][dif];
                }
                dp[i][dif] = 1 + c;
                ans = max(ans, dp[i][dif]);
            }
        }
        return ans;
    }
};