class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int>m;
        for(auto i:words){
            m[i]++;
        }
        int odd=0;
        int ans = 0;
        for(auto i:m){
            string s = i.first;
            if(s[0]==s[1]){
                if(m[s]%2==0){
                    ans+=m[s]*2;
                }
                else{
                    ans+=(m[s]-1)*2;
                    odd++;
                }
                m[s]=0;
            }
            else{
                reverse(s.begin(), s.end());
                if(m[s]>0){
                    ans+=min(m[s], m[i.first])*4;
                }
                m[s]=0;
                m[i.first]=0;
            }
        }
        if(odd>0){
            ans+=2;
        }
        return ans;
    }
};