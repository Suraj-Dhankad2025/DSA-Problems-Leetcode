class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int ans =1;
        int i=0,j=1;
        while(j<n){
            if(nums[j]<=nums[j-1]){
                i = j;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};