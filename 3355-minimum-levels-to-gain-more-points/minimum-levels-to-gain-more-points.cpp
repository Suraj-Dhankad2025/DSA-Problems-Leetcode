class Solution {
public:
    int minimumLevels(vector<int>& p) {
        int ans = INT_MAX;
        vector<pair<int, int>>v;
        int one = 0;
        int zero = 0;
        for(int i=0; i<p.size(); i++){
            if(p[i]==1){
                one++;
            }
            else{
                zero++;
            }
            v.push_back({zero, one});
        }
        for(int i=0; i<p.size()-1; i++){
            int points = v[i].second - v[i].first;
            int score = (one-v[i].second) - (zero-v[i].first);
            if(points>score){
                ans = min(ans, i+1);
            }
        }
        if(ans == INT_MAX)return -1;
        return ans;
    }
};