class Solution {
public:
     int maxFrequency(vector<int>& nums, int k) {
        long long int prefix=0;
        sort(nums.begin(), nums.end());
        int ans=0;
        int i=0;
        int j=0;
        while(j<nums.size()){
            prefix+=nums[j];
            if(k>=(long long)nums[j]*(j-i+1)-prefix){
                ans = max(ans, j-i+1);
            }
            else{
                while(k<(long long)nums[j]*(j-i+1)-prefix){
                prefix = prefix - nums[i];
                i++;
                }
            } 
            j++;  
        }
        return ans;
    }
};