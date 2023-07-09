class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& r) {
        long long int ans = 0;
        int n = r.size();
        unordered_map<double, int>m;
        for(int i=0; i<n; i++){
            double w = r[i][0];
            double h = r[i][1];
            double v = w/h;
            m[v]++;
        }
        for(auto i:m){
            if(i.second>1){
                while(i.second!=1){
                    i.second--;
                    ans+=i.second;
                }
            }
        }
        return ans;
    }
};