class Solution {
public:
    int equalSubstring(string s, string t, int cost) {
        int i=0,j=0;
        int ans=0;
        while(j<s.size()){
            if(s[j]==t[j]){
                ans = max(ans, j-i+1);
                j++;
                continue;
            }
            cost -= abs(s[j]-t[j]);
            while(cost<0 && i<j){
                cost += abs(s[i]-t[i]);
                i++;
            }
            if(cost>=0)ans = max(ans, j-i+1);
            // cout<<i<<" "<<j<<endl;
            // cout<<ans<<endl;
            j++;
        }
        return ans;
    }
};