class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
       
       vector<int>v;
       v.push_back(nums[0]);
       for(int i=1; i<nums.size(); i++){
           if(nums[i]>=v.back()){
               v.push_back(nums[i]);
           }
           else{
            int x = upper_bound(v.begin(), v.end(), nums[i])- v.begin();
            v[x] = nums[i]; 
           }
       }
       return v.size()>=nums.size()-1;
    }
};