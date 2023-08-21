class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
         vector<int>adj[n];
         vector<int>in(n,0);
         for(int i=0; i<n; i++){
            if(leftChild[i]!=-1){
                adj[i].push_back(leftChild[i]);
                in[leftChild[i]]++;
            }
            if(rightChild[i]!=-1){
                adj[i].push_back(rightChild[i]);
                in[rightChild[i]]++;
            }
         }
        vector<int>vis(n,0);
        queue<int>q;
        for(int i=0; i<n; i++){
            if(in[i]==0){
                q.push(in[i]);
            }
        }
        if(q.size()!=1)return false;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(vis[it]!=1){
                    vis[it] = 1;
                    q.push(it);
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};