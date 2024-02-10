class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int numberOfPairs(vector<vector<int>>& p) {
        int ans=0;
        sort(p.begin(), p.end(), cmp);
        int n = p.size();
        for (int i = 0; i < n; i++) {
            int bar = -1000000;
            for (int j = i+1; j < n; j++) {
                if(p[i][1]<p[j][1])continue;
                if(bar<p[j][1]){
                    bar = p[j][1];
                    ans++;
                }
            }
        }
        return ans;
    }
};