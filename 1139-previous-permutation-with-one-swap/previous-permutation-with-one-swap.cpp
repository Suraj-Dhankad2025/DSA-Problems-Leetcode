class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int i1 = -1;
        for(int i=n-2; i>=0; i--){
            if(arr[i]>arr[i+1]){
                i1 = i;
                break;
            }
        }
        if(i1==-1)return arr;
        int i2 = -1;
        int maxi = -1;
        for(int i=i1+1; i<n; i++){
            if(arr[i1]>arr[i] && maxi<arr[i]){
                maxi = arr[i];
                i2 = i;
            }
        }
        swap(arr[i1], arr[i2]);
        return arr;
    }
};