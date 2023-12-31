class Solution {
public:
    int find(vector<int>&nums, int mid){
        int n = nums.size();
        int sum=0;
        int a=1;
        for(int i=0; i<n;i++){
            sum = sum + nums[i];
            if(sum>mid){
                a++;
                sum = nums[i];
            }
        }
        return a;
    }
    int splitArray(vector<int>& nums, int k) {
        int s = *max_element(nums.begin(), nums.end());
        int e = 0;
        for(int i=0; i<nums.size(); i++){
            e = e + nums[i];
        }
        
        while(s<=e){
            int mid = s + (e-s)/2;
            if(find(nums, mid)<=k){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
};