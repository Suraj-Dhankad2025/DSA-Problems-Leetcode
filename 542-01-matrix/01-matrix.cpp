class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
         int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>>vis(n, vector<int>(m, 0));
	    vector<vector<int>>dis(n, vector<int>(m, 0));
	    queue<pair<pair<int, int>, int>>q;
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j]==0){
	                q.push({{i, j}, 0});
	                vis[i][j]=1;
	            }
	            else{
	                vis[i][j]=0;
	            }
	        }
	    }
	    while(!q.empty()){
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int d = q.front().second;
	        q.pop();
	        dis[r][c] = d;
	        int dr[4] = {1, -1, 0, 0};
	        int dc[4] = {0, 0, -1, 1};
	        for(int i=0; i<4; i++){
	            int nc = c + dc[i];
	            int nr = r + dr[i];
	            if(nr<n && nr>=0 && nc<m && nc>=0 && vis[nr][nc]!=1){
	                q.push({{nr, nc}, d+1});
	                vis[nr][nc]=1;
	            }
	        }
	    }
	    return dis;
    }
};