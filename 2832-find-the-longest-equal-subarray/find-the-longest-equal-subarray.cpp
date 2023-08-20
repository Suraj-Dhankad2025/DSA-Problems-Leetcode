class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
       
        unordered_map<int, int>m;
        int left=0;
        int maxl=0;
        int high=0;
        for(int i=0; i<nums.size(); i++){
            high=max(high,++m[nums[i]]);
            while(i-left-high>=k){
                m[nums[left]]--;
                if(m[nums[left]]==0){
                    m.erase(nums[left]);
                }
                left++;
            }
            maxl = max(maxl,high);
        }
       
        return maxl;
    }
};