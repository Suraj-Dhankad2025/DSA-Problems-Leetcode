class Solution {
public:
    void findlps(string s, vector<int>&lps){
        int pre = 0, suff = 1;
        while(suff < s.size()){
            if(s[pre]==s[suff]){
                lps[suff] = pre+1;
                suff++; pre++;
            }
            else {
                if(pre==0) suff++;
                else {
                    pre = lps[pre-1];
                }
            }
        }
    }
    int KMP_MATCH(string main, string find){
        vector<int>lps(find.size(), 0);
        findlps(find, lps);

        int pre = 0, suff = 0;
        while(pre < main.size() && suff < find.size()){
            if(main[pre]==find[suff]){
                pre++; suff++;
            }
            else {
                if(suff==0) pre++;
                else suff = lps[suff-1];
            }
        }
        if(suff==find.size()) return 1;
        else return 0;
    }
    int repeatedStringMatch(string a, string b) {
        if(a==b) return 1;

        int repeatation = 1;
        string newstr = a;
        while(newstr.size() < b.size()){
            newstr+=a;
            repeatation++;
        }

        // searching using kmp 
        if(KMP_MATCH(newstr, b)==1) return repeatation;
        if(KMP_MATCH(newstr+a, b)==1) return repeatation+1;
        return -1;
    }
};