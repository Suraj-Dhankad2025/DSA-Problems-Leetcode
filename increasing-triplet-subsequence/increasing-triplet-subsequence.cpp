class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(ans.begin(), ans.end(), nums[i])-ans.begin();
                ans[ind] = nums[i];
            }
            if(ans.size()==3)return true;
        }
        return false;
    }
};