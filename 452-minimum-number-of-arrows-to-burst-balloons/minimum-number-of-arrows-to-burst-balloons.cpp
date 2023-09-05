class Solution {
    bool static cmp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        int n = p.size();
        int ans=0;
        sort(p.begin(), p.end(), cmp);
        int r=p[0][1];
        for(int i=1; i<n; i++){
            if(r>=p[i][0]){
                ans++;
            }
            else{
                r = p[i][1];
            }
        }
        return n-ans;
    }
};