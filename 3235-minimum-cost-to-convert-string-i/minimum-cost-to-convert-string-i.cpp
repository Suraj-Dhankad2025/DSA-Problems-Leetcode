class Solution {
public:
    long long find(vector<vector<pair<int, int>>>&g, int s, int t){
        queue<pair<int, int>>q;
        long long res=LONG_MAX;
        vector<long long> pathCost(26, LONG_MAX);
        pathCost[s] = 0;
        q.push({s,0});
        while(!q.empty()){
            auto [node, cost] = q.front();
            q.pop();
            for(auto [n,c]:g[node]){
                if(cost+c>=pathCost[n])continue;
                q.push({n, cost+c});
                pathCost[n] = cost + c;
                if(n==t){
                    res = cost + c;
                }
            }
        }
        return (res==LONG_MAX)? -1:res;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long ans=0;
        int n = cost.size();
        vector<vector<pair<int, int>>>graph(26);
        for(int i=0; i<n; i++){
            graph[original[i]-'a'].push_back({changed[i]-'a', cost[i]});
        }

        unordered_map<long long, long long>m;

        for(int i=0; i<source.size(); i++){
            if(source[i]==target[i]){
                continue;
            }
            long long tempCost = -1;
            long long hash = (source[i]-'a')*100 + target[i] - 'a';
            if(m.find(hash)!=m.end()){
                tempCost = m[hash];
            }
            else{
                tempCost = find(graph, source[i]-'a', target[i]-'a');
                m[hash] = tempCost;
            }
            
            if(tempCost==-1)return -1;
            ans+=tempCost;
        }
        return ans;
    }
};