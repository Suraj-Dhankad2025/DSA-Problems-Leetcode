class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int node, int t, vector<int>path, vector<vector<int>>& graph){
        if(node==t){
            ans.push_back(path);
            return ;
        }
        if(path.size()==0){
            path.push_back(0);
        }
        for(auto i:graph[node]){
            path.push_back(i);
            dfs(i, t, path, graph);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int t = graph.size()-1;
        vector<int>path;
         
         dfs(0, t, path, graph);
         return ans;
    }
};