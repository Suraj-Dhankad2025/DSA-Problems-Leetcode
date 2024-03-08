class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int>m;
        int f=0;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
            if(f<m[nums[i]]){
                f = m[nums[i]];
            }
        }
        int ans=0;
        for(auto i:m){
            if(f==i.second){
                ans+=i.second;
            }
        }
        return ans;
    }
};