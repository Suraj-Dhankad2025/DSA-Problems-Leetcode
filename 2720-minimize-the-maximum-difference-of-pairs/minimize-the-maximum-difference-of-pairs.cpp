 class Solution {
public:
    bool find(vector<int>&nums, int maxDif, int p){
        int c=0;
        int dif=0;
        int i=0;
        while(i<nums.size()-1){
            dif = nums[i+1] - nums[i];
            if(dif<=maxDif){
                c++;
                i+=2;
            }
            else{
                i++;
            }
        }
        return c>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int s=0;
        int n=nums.size();
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        int e = nums[n-1]-nums[0];
        while(s<=e){
            int mid = s + (e-s)/2;
            if(find(nums, mid,p)){
                ans = min(ans, mid);
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};