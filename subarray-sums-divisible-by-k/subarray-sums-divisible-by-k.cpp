class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        int ans=0;
        int n =nums.size();
        unordered_map<int, int>m;
        m[0]++;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            sum=((sum)%k + k)%k;
            ans+=m[sum];
            m[sum]++;
        }
        return ans;
    }
};