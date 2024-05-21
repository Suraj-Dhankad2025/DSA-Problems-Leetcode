class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,j=0;
        long long p=1;
        int ans = 0;
        while(j<nums.size()){
            p = p*nums[j];
            while(i<=j && p>=k){
                p = p/nums[i];
                i++;
            }
            ans = ans + (j-i+1);
            j++;
        }
        return ans;
    }
};