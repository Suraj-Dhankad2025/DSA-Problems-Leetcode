class Solution {
public:
    string replaceWords(vector<string>& dict, string s) {
        unordered_map<string, int>m;
        for(int i=0; i<dict.size(); i++){
            m[dict[i]]++;
        }
        string ans="";
        vector<string>v;
        int i=0;
        string t="";
        while(i<s.length()){
            if(s[i]==' '){
                v.push_back(t);
                t="";
                i++;
                continue;
            }
            t+=s[i];
            i++;
            if(m.find(t)!=m.end()){
                while(i<s.length() && s[i]!=' '){
                    i++;
                }
            }
        }
        v.push_back(t);
        for(auto i:v){
            ans+=i;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};