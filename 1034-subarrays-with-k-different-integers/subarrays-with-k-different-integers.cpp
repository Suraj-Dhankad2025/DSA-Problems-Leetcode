class Solution {
public:
    int find(int i, int j, vector<int>& nums, int k){
        map<int, int>m;
        int ans=0;
        while(j<nums.size()){
            m[nums[j]]++;
            while(m.size()>k){
                m[nums[i]]--;
                if(m[nums[i]]==0){
                    m.erase(nums[i]);
                }
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int i=0,j=0;
        return find(i, j, nums, k)-find(i, j, nums, k-1);
    }
};