class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        string start = "JFK";
        map<string, vector<string>> adj;

        for (const auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }
        for (auto& [s, v] : adj) {
            sort(v.rbegin(), v.rend());
        }
        vector<string>path;
        stack<string>st;
        st.push(start);
        while(!st.empty()){
            string node = st.top();
            if(adj[node].empty()){
                path.push_back(node);
                st.pop();
            }
            else{
                string newNode = adj[node].back();
                adj[node].pop_back();
                st.push(newNode);
            }
        }
        reverse(path.begin(), path.end());
        return path;
    }
};