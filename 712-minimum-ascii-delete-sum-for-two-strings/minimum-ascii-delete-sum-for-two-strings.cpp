class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        for(int i=1; i<=s1.size(); i++){
            for(int j=1; j<=s2.size(); j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = s1[i-1] + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        int sum=0;
        for(int i=0; i<s1.size(); i++){
            sum+=s1[i];
        }
        for(int i=0; i<s2.size(); i++){
            sum+=s2[i];
        }
        int sum1=2*dp[s1.size()][s2.size()];
        return sum-sum1;
    }
};