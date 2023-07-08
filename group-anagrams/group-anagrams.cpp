class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>m;
        int n = strs.size();
        for(int i=0; i<n; i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            if(m.find(s)!=m.end()){
                m[s].push_back(strs[i]);
            }
            else{
                vector<string>a;
                a.push_back(strs[i]);
                m[s] = a;
            }
        }
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};