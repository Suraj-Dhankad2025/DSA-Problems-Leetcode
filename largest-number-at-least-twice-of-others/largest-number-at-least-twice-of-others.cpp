class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int l = *max_element(nums.begin(), nums.end());
        int k = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==l){
                k=i;
            }
            else if(l<2*nums[i]){
                return -1;
            }
        }
        return k;
    }
};