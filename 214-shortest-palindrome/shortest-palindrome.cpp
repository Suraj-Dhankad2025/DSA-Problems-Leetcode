class Solution {
public:
    string shortestPalindrome(string str) {
         int n = str.size();
        string a=str;
        a+="$";
        string rev = str;
        reverse(rev.begin(), rev.end());
        a+=rev;
        vector<int>lps(a.size(), 0);
        int ans=0;
        int pre=0,suf=1;
        while(suf<a.size()){
            if(a[pre]==a[suf]){
                lps[suf] = pre+1;
                pre++;
                suf++;
            }
            else{
                if(pre==0){
                    suf++;
                }
                else{
                    pre = lps[pre-1];
                }
            }
        }
        ans = n-lps[lps.size()-1];
        int c=n-1;
        string t="";
        while(ans){
            t+=str[c];
            ans--;
            c--;
        }
        return t+str;
    }
};