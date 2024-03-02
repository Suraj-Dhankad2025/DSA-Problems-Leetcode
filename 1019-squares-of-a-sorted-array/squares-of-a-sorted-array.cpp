class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
        map<int, int>m;
        for(auto i:nums){
            int s = i*i;
            m[s]++;   
        }
        for(auto i:m){
            while(i.second){
                ans.push_back(i.first);
                i.second--;
            }
        }
        return ans;
    }
};