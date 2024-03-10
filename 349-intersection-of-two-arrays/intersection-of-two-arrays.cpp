class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        map<int, int>m;
        for(auto i:nums1){
            m[i]++;
        }
        for(auto i:nums2){
            if(m.find(i)!=m.end()){
                m[i] = -1;
            }
        }
        for(auto i:m){
            if(i.second==-1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};