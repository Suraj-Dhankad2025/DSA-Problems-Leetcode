class Solution {
public:
    set<vector<int>>ans;
    void find(int i, vector<int>&nums){
        if(i==nums.size()){
            ans.insert(nums);
        }
        for(int j=i; j<nums.size(); j++){
            swap(nums[i], nums[j]);
            find(i+1, nums);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        find(0, nums);
        vector<vector<int>>res;
        for(auto i:ans){
            res.push_back(i);
        }
        return res;
    }
};