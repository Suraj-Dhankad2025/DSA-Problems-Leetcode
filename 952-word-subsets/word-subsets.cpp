class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        int m = words2.size();
        
        map<char, int>mp1;
        for(auto i:words2){
            map<char, int>mp;
            for(auto c:i){
                mp[c]++;
            }
            for(auto it:mp){
                mp1[it.first] = max(mp1[it.first], it.second);
            }
        }
        bool f=0;
        vector<string>ans;
        for(auto s:words1){
            map<char, int>mp;
            for(auto c:s){
                mp[c]++;
            }
            f=0;
            for(auto it:mp1){
                if(it.second>mp[it.first]){
                    f=1;
                    break;
                }
            }
            if(f==0)ans.push_back(s);
        }
        return ans;
    }
};