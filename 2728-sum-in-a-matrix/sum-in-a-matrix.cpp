class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int a = 0;
        int ind = nums[0].size()-1;
        int ans=0;
        for(auto &num:nums){
            sort(num.begin(), num.end());
        }
        for(int i=0; i<=ind; i++){
            int a=0;
            for(int j=0; j<n; j++){
                a = max(a, nums[j][i]);
            }
            ans+=a;
        }
        return ans;
    }
};