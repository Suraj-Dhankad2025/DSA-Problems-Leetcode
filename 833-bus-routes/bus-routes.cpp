class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>>mp;
         for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                mp[routes[i][j]].push_back(i);
            }
        }
        vector<int>vis(routes.size(),0);
        queue<pair<int,int>>q;
        q.push({source,0});
        int mini=INT_MAX;
        while(!q.empty()){
            int curr=q.front().first;
            int buses=q.front().second;
            q.pop();
            if(curr==target){
                return buses;
            }
            vector<int>nikalo=mp[curr];
            for(int i=0;i<nikalo.size();i++){
                if(vis[nikalo[i]])continue;
                vis[nikalo[i]]=true;
                vector<int>atthisidx=routes[nikalo[i]];
                for(int j=0;j<atthisidx.size();j++){
                    q.push({atthisidx[j],buses+1});
                }
            }
        }
        return -1;
    }
};