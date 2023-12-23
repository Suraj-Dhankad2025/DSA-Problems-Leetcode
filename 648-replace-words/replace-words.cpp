class Solution {
public:
    string replaceWords(vector<string>& dict, string s) {
        unordered_map<string, int>m;
        for(int i=0; i<dict.size(); i++){
            m[dict[i]]++;
        }
        string ans="";
        int i=0;
        string t="";
        while(i<s.length()){
            if(s[i]==' '){
                ans+=t;
                ans+=" ";
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
        ans+=t;
        return ans;
    }
};