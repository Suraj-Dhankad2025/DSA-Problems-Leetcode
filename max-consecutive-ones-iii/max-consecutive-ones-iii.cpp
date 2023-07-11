class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int c=0,j=0,i=0,n=nums.size();
        int ans =0;
        while(j<n){
            if(nums[j]==0){
                c++;
            }
            while(c>k){
                if(nums[i]==0){
                    c--;
                }
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};