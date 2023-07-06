class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        int ans=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        for(int i=0; i<n; i++){
            if(m.find(abs(nums[i]-k))!=m.end()){
                ans+=m[nums[i]-k];
            }
        }
        return ans;
    }
};