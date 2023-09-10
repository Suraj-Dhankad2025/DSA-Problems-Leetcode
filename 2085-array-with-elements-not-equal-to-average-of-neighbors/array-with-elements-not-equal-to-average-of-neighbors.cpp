class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[i-1]);
            i++;
        }
        if(ans.size()!=nums.size()){
            ans.push_back(nums.back());
        }
        return ans;
    }
};