class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
        vector<pair<int,int>> adj[n];

        for(int i=0;i<edges.size();++i)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }

        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;

        vector<int> dist(n,INT_MAX);
        dist[0]=0;

        //cost,time,node
        pq.push({passingFees[0],0,0});

        while(!pq.empty())
        {
           vector<int> temp=pq.top();
           int node=temp[2];
           int time=temp[1];
           int c=temp[0];
            pq.pop();
            if(node==n-1)return c;

            for(auto i:adj[node])
            {
                auto [new_node,new_time]=i;
                if(time+new_time>maxTime or dist[new_node]<=time+new_time)continue;
                dist[new_node]=time+new_time;
                pq.push({c+passingFees[new_node],time+new_time,new_node});
            }
        }
        return -1;
    }
};