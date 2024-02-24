class Solution {
public:
    int find(vector<int>& nums1, vector<int>& nums2, bool swapped, int i, vector<vector<int>>&dp){
        if(i==nums1.size()){
            return 0;
        }
        if(dp[i][swapped]!=-1)return dp[i][swapped];
        int ans = INT_MAX;
        int prev1 = nums1[i-1];
        int prev2 = nums2[i-1];
        if(swapped){
            swap(prev1, prev2);
        }
        if(nums1[i]>prev1 && nums2[i]>prev2){
            ans = find(nums1, nums2, 0 , i+1, dp);
        }
        if(nums1[i]>prev2 && nums2[i]>prev1){
            ans = min(ans, 1 + find(nums1, nums2, 1, i+1, dp));
        }
        return dp[i][swapped] = ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        vector<vector<int>>dp(nums1.size(), vector<int>(2, -1));
        return find(nums1, nums2, 0, 1, dp);
    }
};