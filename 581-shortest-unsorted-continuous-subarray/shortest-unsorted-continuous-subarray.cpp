class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>v=nums;
        sort(nums.begin(), nums.end());
        int j=n-1;
        int i=0;
        while(j>=0 && nums[j]==v[j]){
            j--;
        }
        while(i<n && nums[i]==v[i]){
            i++;
        }
        if(j<0 || i>n-1)return 0;
        return j-i+1;
    }
};