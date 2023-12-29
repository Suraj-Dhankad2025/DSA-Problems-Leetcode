class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int i=0,j=0;
        int c=0;
        int ans=0;
        while(j<n){
            int ch = s[j];
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                c++;
            }
            while(j-i+1>k){
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
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