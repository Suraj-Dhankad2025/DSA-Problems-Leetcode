class Solution {
public:
     int minOperations(vector<int>& nums, int x) {

       int n = nums.size();
       long long int k=0;
       for(auto it:nums){
           k+=it;
       }
       k = k - x;
       if(k<0)return -1; 
       long long int sum=0;
       int i=0;
       int j = 0;
       int ans=-1;
       while(j<n){
           sum = sum + nums[j];
           if(sum>k){
               while(sum>k){
                   sum-=nums[i];
                   i++;
               }
           }
           if(sum==k){
               ans = max(ans, j-i+1);
           }
           j++;
       }
       if(ans==-1){
           return -1;
       }
       return n-ans;
     } 
};