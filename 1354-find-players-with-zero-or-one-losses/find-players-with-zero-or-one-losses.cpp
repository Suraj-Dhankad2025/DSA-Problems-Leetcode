class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
         vector<vector<int>>ans(2);
        map<int, int>m1;
        
        int n = m.size();
        for(int i=0; i<n; i++){
            m1[m[i][1]]++;
        }
        map<int, int>m2;
        for(int i=0; i<n; i++){
            if(m1.find(m[i][0])==m1.end() && m2[m[i][0]]==0){
                ans[0].push_back(m[i][0]);
                m2[m[i][0]]++;
            }
        }
        for(auto i:m1){
            if(i.second==1){
                ans[1].push_back(i.first);
            }
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};