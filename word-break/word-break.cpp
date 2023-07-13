class Solution {
public:
     bool badhiya(string s,set<string>&st,int ind,vector<int>&dp){
        if(ind>=s.length()){
            return true;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        for(int i=ind;i<s.length();i++){
            if(st.find(s.substr(ind,i-ind+1))!=st.end()){ 
                if( badhiya(s,st,i+1,dp)){
                    return dp[ind]=1;
                }
            }
        }
        return dp[ind]= 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(int i=0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        vector<int>dp(s.length(),-1);
        return badhiya(s,st,0,dp);
    }
};