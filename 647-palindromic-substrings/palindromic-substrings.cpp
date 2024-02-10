class Solution {
public:
    int palin(int i, int j,string &s){
        int cnt = 0;
        while(i >= 0 && j < s.length() && s[i] == s[j]){
            cnt++;
            i--;
            j++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int cnt = 0;
        for(int i = 0; i < s.length() ;i++){
           int j = i;
           int oddLengthVale = palin(i,j , s);
           int evenLengthVale= palin(i , j+1 ,s);
           cnt += (oddLengthVale + evenLengthVale);
        }
        return cnt;
        
    }
};