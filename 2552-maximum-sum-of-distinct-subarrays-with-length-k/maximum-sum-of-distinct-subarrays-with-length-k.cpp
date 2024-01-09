class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=INT_MIN;
        int i=0;
        int j=0;
        long long sum=0;
        unordered_map<int,int>map;
        while(j<nums.size()){
            sum=sum+nums[j];
            map[nums[j]]++;
            if((j-i+1)<k){
                j++;
            }
            else if((j-i+1)==k){
                if(map.size()==k){
                    ans=max(ans,sum);
                    
                }
                map[nums[i]]--;
                sum=sum-nums[i];
                if(map[nums[i]]==0){
                    map.erase(nums[i]);
                }
                i++;
                j++;
            }
        }
        if(ans==INT_MIN){
            return 0;
        }
        else{
            return ans;
        }
        
    }
    
};