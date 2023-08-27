class Solution {
public:
    int find(vector<int>&v1 , vector<int>&v2){
        return abs(abs(v1[0]-v2[0]) + abs(v1[1]-v2[1]));
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
         int n = points.size();
         vector<pair<int,int>>adj[n];
         for(int i=0; i<n ; i++){
            for(int j=i+1;j<n ; j++){
                adj[i].push_back({j,find(points[i],points[j])});
                adj[j].push_back({i,find(points[i],points[j])});
            }
        }
         priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>>pq;
      
       vector<int>vis(n,0);
       pq.push({0,0});
       int sum = 0;
       while(!pq.empty()){
           int node = pq.top().second;
           int wt = pq.top().first;
           pq.pop();
           if(vis[node]==1)continue;
           vis[node] = 1;
           sum+=wt;
           for(auto i:adj[node]){
               int adjNode = i.first;
               int edgeWt = i.second;
               if(!vis[adjNode]){
                   pq.push({edgeWt, adjNode});
               }
           }
       }
       return sum;
    }
};