class Solution {
public:
    int search(vector<int>& a, int target) {
        int s=0;
        int e = a.size()-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(a[mid]==target){
                return mid;
            }
            else if(a[s]<=a[mid]){
                if(a[s]<=target && a[mid]>=target){
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
            }
            else{
                if(a[e]>=target && a[mid]<=target){
                    s = mid+1;
                }
                else{
                    e = mid-1;
                }
            }
        }
        return -1;
    }
};