class Solution {
public:
    int maxPower(string s) {
        int i=0; 
        int j=0;
        int n = s.size();
        int ans=0;
        int count=0;
        vector<int>f(26, 0);
        int l=0;
        while(j<n){
            f[s[j]-'a']++;
            if(l<f[s[j]-'a']){
                l = f[s[j]-'a'];
            }
            while(j-i+1-l >0){
                f[s[i]-'a']--;
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