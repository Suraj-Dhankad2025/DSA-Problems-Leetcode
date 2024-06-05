class Solution {
public:
    string minWindow(string s, string t) {
        map<int, int>m;
        int c = 0;
        for(auto i:t){
            if(m[i]==0){
                c++;
            }
            m[i]++;
        }
        string ans = "";
        int len=INT_MAX;
        int i=0,j=0;
        int x=-1,y=-1;
        while(j<s.size()){
            m[s[j]]--;
            if(m[s[j]]==0){
                c--;
            }
            while(i<s.size() && c==0){
                m[s[i]]++;
                if(m[s[i]]==1){
                    c++;
                }
                if(len>j-i+1){
                    x = i;
                    y = j;
                    len = j-i+1;
                }
                i++;
            }
            j++;
        }
        if(x==-1)return ans;
        for(int i=x; i<=y; i++){
            ans+=s[i];
        }
        return ans;
    }
};