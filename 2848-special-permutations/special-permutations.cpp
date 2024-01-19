
const int MOD = 1e9 + 7;
class Solution {
public:
    int find(const vector<int>& nums, int prev, int index, int mask, vector<vector<int>>& dp) {
        if (index == nums.size()) {
            return 1;
        }
        if (dp[prev + 1][mask] != -1) {
            return dp[prev + 1][mask];
        }
        int total = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (!(mask & (1 << i)) && (prev == -1 || nums[i] % nums[prev] == 0 || nums[prev] % nums[i] == 0)) {
                total = (total + find(nums, i, index + 1, mask | (1 << i), dp)) % MOD;
            }
        }
        dp[prev + 1][mask] = total;
        return total;
    }
    int specialPerm(const vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>((1 << nums.size()), -1));
        return find(nums, -1, 0, 0, dp);
    }
};