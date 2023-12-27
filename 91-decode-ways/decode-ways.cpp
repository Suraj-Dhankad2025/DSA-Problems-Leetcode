class Solution {
public:
    int find(int i,string &s, vector<int>&dp){
        if(i<0){
            return 1;
        }
        if(dp[i]!=-1)return dp[i];
        int one = 0;
        if(s[i]!='0'){
            one = find(i-1, s, dp);
        }
        int two = 0;
        if(i-1>=0 && s[i-1]!='0'){
            int num = (s[i-1]-'0')*10 + (s[i]-'0');
            if(num<=26){
                two = find(i-2, s, dp);
            }
        }
        return dp[i] = one+two;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);
        return find(s.size()-1,s, dp);
    }
};