class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;
        int n = heights.size();
        int m = heights[0].size();
        pq.push({0,{0,0}});
        vector<vector<int>>v(n,vector<int>(m,1e9));
        v[0][0] = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!pq.empty()){
            int dif = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1){
                return dif;
            }
            for(int i=0; i<4; i++){
                int nr = row+dr[i];
                int nc = col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int effort = max(abs(heights[nr][nc] - heights[row][col]), dif);
                    if(effort<v[nr][nc]){
                        v[nr][nc] = effort;
                        pq.push({effort,{nr,nc}});
                    } 
                }
            }
        }
        return 0;
    }
};