class Solution {
public:
    long long taskSchedulerII(vector<int>& nums, int space) {
        long long int ans=0;
        unordered_map<long long int, long long int>m;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(m.find(nums[i])==m.end()){
                m[nums[i]] = 1 + ans + space;
                ans++;
            }
            else{
                if(m[nums[i]]>ans){
                    ans = m[nums[i]];
                }
                m[nums[i]] = space + ans + 1;
                ans++;
            }
        }
        return ans;
    }
};