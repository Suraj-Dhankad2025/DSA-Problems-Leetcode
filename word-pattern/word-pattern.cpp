class Solution {
public:
    bool wordPattern(string p, string s) {
        map<char, string>m;
        map<string, char>m1;
        int j=0,i;
        for(i=0; i<p.size()&&j<s.size(); i++){
            string st = "";
            while(s[j]!=' ' && j<s.size()){
                st+=s[j];
                j++;
            }
            if(m.find(p[i])==m.end() && m1.find(st)==m1.end()){
                m[p[i]] = st;
                m1[st] = p[i];
            }
            else{
                if(m[p[i]]!=st){
                    return false;
                }
                else if(m1[st]!=p[i]){
                    return false;
                }
            }
            j++;
        }

        if(j<s.size()||i<p.size())return false;
        return true;
    }
};