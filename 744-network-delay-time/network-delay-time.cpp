class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>>mat(n, vector<int>(n,INT_MAX));
        for(int i=0; i<times.size(); i++){
            int u = times[i][0]-1;
            int v = times[i][1]-1;
            int t = times[i][2];
            mat[u][v] = t;
        }
        for(int i=0; i<n; i++){
            mat[i][i] = 0;
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(mat[i][k]==INT_MAX || mat[k][j]==INT_MAX)continue;
                    mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                }
            }
        }
        
        k--;
        int ans = -1;
        for(int i=0; i<n; i++){
            if(mat[k][i]==INT_MAX)return -1;
            ans = max(ans, mat[k][i]);
        }
        return ans;
    }
};
    