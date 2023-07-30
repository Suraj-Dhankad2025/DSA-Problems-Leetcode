class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi=0;
        int currsum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            currsum+=nums[i];
            maxi=max(maxi,abs(currsum));
            if(currsum>0){
                currsum=0;
            }
        }
        currsum=0;
        for(int i=0;i<n;i++){
            currsum+=nums[i];
            maxi=max(maxi,currsum);
            if(currsum<0){
                currsum=0;
            }
        }
        return maxi;
    }
};