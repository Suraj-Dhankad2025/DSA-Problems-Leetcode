class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n, -1);
        long long sum=0;
        int i=0,j=0;
        int s = 2*k + 1;
        while(j<n){
            sum+=nums[j];
            if(j-i+1==2*(k) + 1){
                ans[j-k] = sum/s;
                sum = sum - nums[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};