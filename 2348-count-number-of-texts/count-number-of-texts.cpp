class Solution {
public:
    int mod = 1e9+7;
    int find(int i, string &s, unordered_map<char, int>&m, vector<int>&dp){
        if(i>=s.size()){
            return 1;
        }
        if(dp[i]!=-1)return dp[i];
        int ans=0;
        int k = m[s[i]];
        for(int ind=i; ind<s.size() && ind-i<k; ind++){
            if(s[i]!=s[ind]){
                break;
            }
            ans = (ans%mod + find(ind+1, s, m, dp)%mod)%mod;      
        }
        return dp[i] = ans%mod;
    }
    int countTexts(string s) {
        unordered_map<char, int>m;
        vector<int>dp(s.size()+1,-1);
        m['2'] = 3;
        m['3'] = 3;
        m['4'] = 3;
        m['5'] = 3;
        m['6'] = 3;
        m['7'] = 4;
        m['8'] = 3;
        m['9'] = 4;
        return find(0,s,m, dp);
    }
};