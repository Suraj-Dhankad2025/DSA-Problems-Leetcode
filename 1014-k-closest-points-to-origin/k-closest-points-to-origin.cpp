class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans(k, vector<int>(2,-1));
        priority_queue<pair<int, pair<int , int>>>pq;
        for(int i=0; i<points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int dis = x*x + y*y;
            pq.push({dis,{x,y}});
            if(pq.size()>k)pq.pop();
        }
        int j=0;
        while(!pq.empty()){
            ans[j][0] = pq.top().second.first;
            ans[j][1] = pq.top().second.second;
            j++;
            pq.pop();
        }
        return ans;
    }
};