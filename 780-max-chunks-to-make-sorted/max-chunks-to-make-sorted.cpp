class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int>maxi(n, 0);
        maxi[0] = arr[0];
        for(int i=1; i<n; i++){
            maxi[i] = max(maxi[i-1], arr[i]);
        }
        int c=0;
        for(int i=0; i<n; i++){
            if(maxi[i]==i){
                c++;
            }
        }
        return c;
    }
};