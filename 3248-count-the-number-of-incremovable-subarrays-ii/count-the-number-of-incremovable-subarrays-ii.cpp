class Solution {
public:
    long long find(vector<int>& a, vector<int>& b){
        int i=0,j=0;
        int n1=a.size();
        int n2=b.size();
        long long res=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<b[j]){
                res+=(n2-j);
                i++;
            }
            else{
                j++;
            }
        }
        return res;
    }
    long long incremovableSubarrayCount(vector<int>& nums) {
        long long n = nums.size();
        if(n==1)return 1;
        int i=0,j=n-1;
        vector<int>arr1,arr2;
        while(i+1<n && nums[i]<nums[i+1]){
            arr1.push_back(nums[i]);
            i++;
        }
        arr1.push_back(nums[i]);
        while(j>=1 && nums[j]>nums[j-1]){
            arr2.push_back(nums[j]);
            j--;
        }
        arr2.push_back(nums[j]);
        long long ans=0;
        reverse(arr2.begin(), arr2.end());
        if(j<i){
            long long x = (1ll*n*(n+1)*1LL)/2;
            return x;
        }
        ans+=arr1.size();
        ans+=arr2.size();
        ans+=1;
        ans+=find(arr1, arr2);
        return ans;
    }
};