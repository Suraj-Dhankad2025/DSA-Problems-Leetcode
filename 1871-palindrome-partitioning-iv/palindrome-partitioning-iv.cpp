class Solution {
    bool ispalin(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
    int palin(string &s,int i,int k,vector<vector<int>>&dp){
        if(i>=s.size()){
            if(k>0)return 1e5;
            return 0;
        }
        if(k==0){
            return 1e5;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int take=1e5;
        for(int j=i;j<s.size();j++){
            bool cnt=ispalin(s,i,j);
            if(cnt){
                take=min(take,palin(s,j+1,k-1,dp));
            }
        }
        return dp[i][k]= take;
    }
public:
    bool checkPartitioning(string s) {
        int k=3;
        vector<vector<int>>dp(s.size(),vector<int>(k+1,-1));
        int x= palin(s,0,k,dp);
        if(x>=1e5)return 0;
        return 1;
    }
};