class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int s=points[0][0];
        int e=points[0][1];
        int ans=1;
        for(int i=1; i<n; i++){
            if(s<=points[i][0] && e>=points[i][0]){
                s=points[i][0];
                e = min(points[i][1], e);
            }
            else{
                ans++;
                s = points[i][0];
                e = points[i][1];
            }
        }
        return ans;
    }
};