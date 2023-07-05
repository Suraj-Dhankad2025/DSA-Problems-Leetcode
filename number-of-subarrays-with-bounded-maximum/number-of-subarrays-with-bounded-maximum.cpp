class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int ans=0;
        int s=-1,e=-1;
        for(int i=0; i<n; i++){
            if(nums[i]>right){
                s = i;
            }
            if(nums[i]>=left){
                e = i;
            }
            ans+=(e-s);
        }
        return ans;
    }
};