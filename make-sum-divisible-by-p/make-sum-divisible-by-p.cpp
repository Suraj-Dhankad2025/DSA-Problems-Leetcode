class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = 0;
        int res = INT_MAX;
        int curr = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int k = sum % p;
        if (k == 0) {
            return 0;
        }
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            curr = (curr + nums[i]) % p;
            int temp = (curr - k + p) % p;

            if (mp.find(temp) != mp.end()) {
                res = min(res, i - mp[temp]);
            }
            mp[curr] = i;
        }
        if (res == INT_MAX || res == n) {
            return -1;
        }
        return res;
    }
};