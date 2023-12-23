class Solution {
public:
    int solve(int ind,vector<string>&temp,int zero,int one ,vector<string>& strs ,vector<vector<vector<int>>>&dp){
        if(ind>=strs.size())
        {
            if(zero>=0&&one>=0)
            return 0;
            else  return -1e9;
        }
        if(one<0||zero<0) return -1e9;
        if(dp[ind][zero][one]!=-1) return dp[ind][zero][one];

        int o=0,z=0;
        string a=strs[ind];
        for(int i=0;i<a.size();i++)
        {
            if(a[i]=='0') z++;
            if(a[i]=='1') o++;
        }
        
        temp.push_back(strs[ind]);
        int take=1+solve(ind+1,temp,zero-z,one-o,strs,dp);
        temp.pop_back();

        int not_take=solve(ind+1,temp,zero,one,strs,dp);

        return dp[ind][zero][one]=max(take,not_take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<string>temp;
        vector<vector<vector<int>>>dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,temp,m,n,strs,dp);
    }
};