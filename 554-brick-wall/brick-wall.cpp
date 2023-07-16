class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
       unordered_map<int,int>mp;
        int n=wall.size();
        int lastlen=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<wall[i].size();j++){
                sum+=wall[i][j];
                mp[sum]++;
            }
            lastlen=sum;
        }
        int maxi=0;
        for(auto it:mp){
            if(it.second>maxi&&it.first!=lastlen){
                maxi=it.second;
            }
        }
        return n-maxi;
    }
};