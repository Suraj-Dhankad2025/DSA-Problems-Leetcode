class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dis(n ,vector<int>(n, INT_MAX));
        for(auto i:edges){
            dis[i[0]][i[1]] = i[2];
            dis[i[1]][i[0]] = i[2];
        }
        for(int i=0; i<n; i++){
            dis[i][i] = 0;
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dis[i][k]==INT_MAX || dis[k][j]==INT_MAX){
                        continue;
                    }
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        int city=-1;
        int count=n;
        for(int i=0; i<n; i++){
            int c=0;
            for(int j=0; j<n; j++){
                if(dis[i][j]<=distanceThreshold){
                    c++;
                }
            }
            if(c<=count){
                city = i;
                count = c;
            }
        }
        return city;
    }
};