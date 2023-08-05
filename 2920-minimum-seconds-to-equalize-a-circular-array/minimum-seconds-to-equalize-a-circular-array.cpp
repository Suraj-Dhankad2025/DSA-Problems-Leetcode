class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        map<int, vector<int>>m;
        int n=nums.size();
        for(int i=0; i<n; i++){
            m[nums[i]].push_back(i);
        }
        int res=INT_MAX;
        for(auto it:m){
            int res1 = INT_MIN;
            vector<int>v = it.second;
            for(int i=0; i<v.size()-1; i++){
                res1 = max(res1, (v[i+1] - v[i])/2);
            }
            res1=max(res1, (v[0]+n-v[v.size()-1])/2);
            res = min(res1, res);
        }
        return res;
    }
  
};