class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++) ans += (i * nums[i]);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int curr = ans;
        for(int i=n-1; i>=0; i--) {
            curr = curr - (n-1)*nums[i] + (sum-nums[i]);
            ans = max(ans, curr);
        }
        return ans;
    }
};