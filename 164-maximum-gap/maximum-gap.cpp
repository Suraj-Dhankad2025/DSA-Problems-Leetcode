class Solution {
public:
    vector<int> find(vector<int> nums){
        map<int, int>m;
        for(auto i:nums){
            m[i]++;
        }
        nums.erase(nums.begin(), nums.end());
        for(auto i:m){ 
            while(i.second>0){
                nums.push_back(i.first);
                i.second--;
            }
        }
        return nums;
    }
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<2)return 0;
        nums = find(nums);
        int ans = 0;
        for(int i=0; i<n-1; i++){
            ans = max(ans, nums[i+1] - nums[i]);
        }
        return ans;
    }
};