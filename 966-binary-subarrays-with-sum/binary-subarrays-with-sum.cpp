class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        m[0]=1;
        int pre = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            pre+=nums[i];
            if(m.find(pre-k)!=m.end()){
                ans+=m[pre-k];
            }
            m[pre]++;
        }
        return ans;
    }
};