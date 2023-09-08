class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>>v;
        sort(a.begin(), a.end());
        int n = a.size();
        for(int i=0; i<n; i++){
          if(v.empty() || a[i][0]>v.back()[1]){
              v.push_back(a[i]);
          }
          else{
              v.back()[1] = max(v.back()[1], a[i][1]);
          }
        }
        return v;
    }
};