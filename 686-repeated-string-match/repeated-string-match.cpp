class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int ans=0;
        string s = a;
        if(a == b) return 1;
        while(s.length()<=10000){
            if(s.find(b)!=-1){
                return ans+1;
            }
            s+=a;
            ans++;
        }
        return -1;
    }
};