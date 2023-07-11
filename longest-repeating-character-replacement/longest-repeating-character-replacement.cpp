class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0; 
        int j=0;
        int n = s.size();
        int ans=0;
        int count=0;
        vector<int>f(26, 0);
        int l=0;
        while(j<n){
            f[s[j]-'A']++;
            if(l<f[s[j]-'A']){
                l = f[s[j]-'A'];
            }
            while(j-i+1-l >k){
                f[s[i]-'A']--;
                i++;
                for(int it=0; it<26; it++){
                    if(l<f[it]){
                        l = f[it];
                    }
                }
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};