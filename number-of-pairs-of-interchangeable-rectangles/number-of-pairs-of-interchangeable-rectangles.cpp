class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& r) {
        long long int ans = 0;
        int n = r.size();
        unordered_map<double, long long int>m;
        for(int i=0; i<n; i++){
            double w = r[i][0];
            double h = r[i][1];
            double v = w/h;
            if(m.find(v)!=m.end()){
                ans+=m[v];
            }
            m[v]++;
        }
        return ans;
    }
};