class Solution {
public:
    bool checkZeroOnes(string s) {
        int i=0,j=0,n=s.size();
        int ans=0;
        while(j<n){
            if(s[j]=='0'){
                i = j+1;

            }
            ans = max(ans, j-i+1);
            j++;
        }
        i=0,j=0;
        int ans1=0;
        while(j<n){
            if(s[j]=='1'){
                i = j+1;
            }
            ans1 = max(ans1, j-i+1);
            j++;
        }
        if(ans>ans1)return true;
        return false;
    }
};