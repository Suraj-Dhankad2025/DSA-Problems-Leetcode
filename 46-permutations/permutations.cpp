class Solution {
public:
    vector<vector<int>>ans;
    void find(unordered_map<int,int>&vis, vector<int>&a, vector<int>&nums){
        if(a.size()==nums.size()){
            ans.push_back(a);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                a.push_back(nums[i]);
                vis[i]=1;
                find(vis,a,nums);
                vis[i]=0;
                a.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>a;
        unordered_map<int,int>vis;
        find(vis,a, nums);
        return ans;
    }
};