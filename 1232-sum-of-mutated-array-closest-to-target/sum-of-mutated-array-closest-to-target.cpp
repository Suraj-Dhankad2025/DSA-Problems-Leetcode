class Solution {
    int find(int ele,vector<int>&arr){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=ele){
                sum+=ele;
            }
            else{
                sum+=arr[i];
            }
        }
        return sum;
    }
public:
    int findBestValue(vector<int>& arr, int target) {   
       int n = arr.size();
       int s=0;
    //    int sum = accumulate(arr.begin(), arr.end(), 0);
       int e = *max_element(arr.begin(), arr.end());
       int ans=0;
       int mini=INT_MAX;
       while(s<=e){
           int mid = s + (e-s)/2;
           int x=find(mid, arr);
           if(abs(target-x)<=mini){
               if(abs(target-x)==mini){
                   ans=min(ans,mid);
               }
               else{
                   ans=mid;
               }
               mini=abs(target-x);
           }
            if(target-x>0){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
       } 
       return ans;
    }
};