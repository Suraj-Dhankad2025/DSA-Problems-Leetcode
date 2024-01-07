class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0;
        long long prefix=0;
        int i=0,j=0;
        sort(nums.begin(), nums.end());
        while(j<n){
            prefix+=nums[j];
            if(prefix+k>=(long long)nums[j]*(j-i+1)){
                ans = max(ans, j-i+1);
            }
            while(prefix+k<(long long)nums[j]*(j-i+1) && i<nums.size()){
                prefix-=nums[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};