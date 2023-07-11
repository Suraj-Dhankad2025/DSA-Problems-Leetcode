class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,j=0,n=nums.size(),ans=0;
        while(j<n){
            if(nums[j] == 0){
                i = j+1;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};