class Solution {
public:
    
    bool wordBreak(string s, vector<string>& w) {
        int n = s.size();
        vector<bool>dp(n+1, 0);
        dp[n] = 1;
        for(int i = n-1; i>=0; i--){
            for(auto j:w){
                if((i + j.size()) <= n){
                    string t = "";
                    for(int k=i; k<i+j.size(); k++){
                        t+=s[k];
                    }
                    if(t == j){
                        dp[i] = dp[i + j.size()];
                    }
                }
                if(dp[i]==true) break;
            }
        }
        return dp[0];
    }
};