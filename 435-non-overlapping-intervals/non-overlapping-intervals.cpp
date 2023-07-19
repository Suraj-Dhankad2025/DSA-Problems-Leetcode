class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        int ans=0;
        int x = a[0][1];
        for(int i=1; i<n; i++){
            if(x>a[i][0]){
                x = min(x, a[i][1]);
                ans++;
            }
            else{
                x = a[i][1];
            }
        }
        return ans;
    }
};