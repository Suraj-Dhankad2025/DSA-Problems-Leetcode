class Solution {
public:
    int find(int i, int j, vector<vector<int>>& grid){
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        int r = i-1;
        for(int c=j-1; c<=j+1; c++){
            if(r<0 || r>=n || c<0 || c>=m){
                return -1;
            }
            ans+=grid[r][c];
        }
        ans+=grid[i][j];
        r = i+1;
        for(int c=j-1; c<=j+1; c++){
            if(r<0 || r>=n || c<0 || c>=m){
                return -1;
            }
            ans+=grid[r][c];
        }
        return ans;
    }
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m ;j++){
                int sum = find(i, j, grid);
                if(sum!=-1){
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
};