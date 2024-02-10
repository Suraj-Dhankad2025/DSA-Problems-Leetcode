class Solution {
public:
    int check(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]^s[j]){
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=i ;j<n; j++){
                if(check(s.substr(i, j-i+1)) == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};