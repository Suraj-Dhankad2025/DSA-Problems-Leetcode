class Solution {
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    queue<vector<int>>q;
    void dfs(int row,int col,vector<vector<int>>&grid){
        grid[row][col]=2;
        q.push({row,col,0});
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0&&nr<grid.size()&&nc>=0&&nc<grid[0].size()&&grid[nr][nc]!=2&&grid[nr][nc]==1){
                dfs(nr,nc,grid);
            }
        }
        // return;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            bool f=false;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    f=1;
                    dfs(i,j,grid);
                    break;
                }
            }
            if(f){
                break;
            }
        }
        while(!q.empty()){
            int r=q.front()[0];
            int c=q.front()[1];
            int d=q.front()[2];
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0&&nr<grid.size()&&nc>=0&&nc<grid[0].size()){
                    if(grid[nr][nc]==1){
                        return d;
                    }
                    if(grid[nr][nc]==2){
                        continue;
                    }
                    grid[nr][nc]=2;
                    q.push({nr,nc,d+1});
                }
            }
        }
        return 0;
    }
};