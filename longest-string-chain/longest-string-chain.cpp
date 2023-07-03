class Solution {
public:
    bool check(string s, string t){
        if(s.size()!=t.size()+1)return false;
        int a = 0;
        int b = 0;
        while(a<s.size()){
            if(s[a]==t[b]){
                a++;
                b++;
            }
            else{
                a++;
            }
        }
        if(a==s.size()&&b==t.size())return true;
        return false;
    }
    struct cmp{
        bool operator()(string &s, string &t){
        return s.size()<t.size();
    }
    };
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int>dp(n, 1);
        sort(words.begin(), words.end(),cmp());
        int maxi = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(check(words[i], words[j])&&dp[i]<dp[j]+1){
                    dp[i] = 1 + dp[j];
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
            }
        }
        return maxi;
    }
};