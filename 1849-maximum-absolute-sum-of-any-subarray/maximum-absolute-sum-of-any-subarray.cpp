class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum=0;
        int ans=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum+=nums[i];
            ans=max(ans,sum);
            if(sum<0){
                sum = 0;
            }
        }
        int sum1=0;
        for(int i=0; i<n; i++){
            sum1+=nums[i];
            ans= max(ans,abs(sum1));
            if(sum1>0){
                sum1 = 0;
            }
        }
        
        return ans;
    }
};