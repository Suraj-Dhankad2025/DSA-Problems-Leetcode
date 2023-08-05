class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        map<int, vector<int>>m;
        int n=nums.size();
        for(int i=0; i<n; i++){
            m[nums[i]].push_back(i);
        }
        int res=INT_MAX;
        for(auto v:m){
            int res1 = INT_MIN;
            for(int i=0; i<v.second.size()-1; i++){
                res1 = max(res1, (v.second[i+1] - v.second[i])/2);
            }
            res1 = max(res1, (v.second[0]+n-v.second[v.second.size()-1])/2);
            res = min(res1, res);
        }
        return res;
    }
  
};