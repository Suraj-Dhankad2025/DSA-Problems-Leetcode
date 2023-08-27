class Solution {
public:
    int rank(vector<int>&nums,int diff){
        int count=0;
        int i=0;
        int j=1;
        while(i<nums.size()){
            while(j<nums.size()&&nums[j]-nums[i]<=diff){
                j++;
            }
            j--;
            count+=j-i;
            i++;
        }
        return count;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums[n-1]-nums[0];
        int ans=0;
        while(low<high){
            int mid=low+(high-low)/2;
            int x=rank(nums,mid);
            if(x<k){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};