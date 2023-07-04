class Solution {
public:
    bool buddyStrings(string s, string g) {
        if(s.size()!=g.size())return false;
        int a=-1,b=-1;
        int n = s.size();
        if(s==g){
            unordered_map<char, int>m;
            for(int i=0; i<n; i++){
                m[s[i]]++;
                if(m[s[i]]>1)return true;
            }
            return false;
        }
        
        for(int i=0; i<n; i++){
            if(s[i]!=g[i]){
                a = i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(s[i]!=g[i]){
                b = i;
                break;
            }
        }
        swap(s[a], s[b]);
        if(s==g)return true;
        return false;
    }
};