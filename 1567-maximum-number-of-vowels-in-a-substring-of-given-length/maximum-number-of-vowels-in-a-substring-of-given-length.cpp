class Solution {
public:
    int maxVowels(string s, int k) {
        map<char, int>m;
        m['a']++;
        m['e']++;
        m['i']++;
        m['o']++;
        m['u']++;
        int n = s.size();
        int i=0,j=0;
        int c=0;
        int ans=0;
        while(j<n){
            if(m.find(s[j])!=m.end()){
                c++;
            }
            while(j-i+1>k){
                if(m.find(s[i])!=m.end()){
                    c--;
                }
                i++;
            }
            if(j-i+1==k)ans = max(ans, c);
            j++;
        }
        return ans;
    }
};