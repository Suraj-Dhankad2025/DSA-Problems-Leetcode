class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
       int n = heights.size();
       int m = heights[0].size();
       priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;

       vector<vector<int>>v(n, vector<int>(m, INT_MAX));
        v[0][0] = 0;
        pq.push({0,0,0});
        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};
        while(!pq.empty()){
            auto [w, i, j] = pq.top();
            pq.pop();
            if(i==n-1 && j==m-1)return w;
            for(int k=0; k<4; k++){
                int nr = i + dr[k];
                int nc = j + dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int dif = max(w, abs(heights[i][j]-heights[nr][nc]));
                    if(v[nr][nc]>dif){
                        v[nr][nc] = dif;
                        pq.push({dif, nr, nc});
                    }
                }
            }
        }
        return v[n-1][m-1];
    }
};