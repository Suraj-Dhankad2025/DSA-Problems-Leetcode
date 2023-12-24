class Solution {
public:
    long long maxi(long long a, long long b){
        if(a>b){
            return a;
        }
        return b;
    }
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long pre=0;
        long long ans = -1;
        for(int i=0; i<n; i++){
            if(i>=2 && pre>nums[i]){
                ans = maxi(ans, pre+nums[i]);
            }
            pre+=nums[i];
        }
        return ans;
    }
};