class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(x==y)return 0;
        unordered_map<int, int>m;
        queue<pair<int, int>>q;
        q.push({x, 0});
        m[x]++;
        while(!q.empty()){
            auto [node, f] = q.front();
            q.pop();
            if(node==y){
                return f;
            }
            if(node%5==0 && m.find(node/5)==m.end()){
                q.push({node/5, f+1});
                m[node/5]++;
            }
            if(node%11==0 && m.find(node/11)==m.end()){
                q.push({node/11, f+1});
                m[node/11]++;
            }
            if(m.find(node - 1)==m.end()){
                q.push({node-1, f+1});
                m[node-1]++;
            }
            if(m.find(node + 1)==m.end()){
                q.push({node+1, f+1});
                m[node+1]++;
            }
        }
        return -1;
    }
};