class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        vector<pair<int, int>>v;
        for(int i=0; i<m.size(); i++){
            v.push_back({m[i][0], 1});
            v.push_back({m[i][1], -1});
        }
        v.push_back({0, 0});
        v.push_back({days+1, 0});
        sort(v.begin(), v.end());
        int meet = 0;
        int ans = 0;
        for(int i=0; i<v.size()-1; i++){
            meet+=v[i].second;
            if(meet==0){
                ans += max(0,v[i+1].first - v[i].first - 1);
            }
        }
        return ans;
    }
};