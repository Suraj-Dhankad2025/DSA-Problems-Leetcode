class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int n = a.size();
        int s=0,e=n-1;
        
        int mid = 0;
        while(s<e){
            mid = s + (e-s)/2;
            if(a[mid]>a[mid+1]){
                e = mid;
               
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
};