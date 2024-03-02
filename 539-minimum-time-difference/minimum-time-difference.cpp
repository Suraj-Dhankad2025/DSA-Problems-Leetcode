class Solution {
public:
    int findMinDifference(vector<string>& t) {
        vector<int>temp;
        for(auto it:t){
            string ti=it.substr(3,2);
            int t=stoi(it.substr(0,2));
            if(t==0) t=24;
            temp.push_back(stoi(ti)+t*60);
        }
        sort(temp.begin(),temp.end());
        int ans=1e9;
        for(int i=1;i<temp.size();i++)
        {
            ans=min(ans,min( temp[i]-temp[i-1] ,1440-(temp[i]-temp[i-1])));
        }
        ans=min(ans,1440-(temp[temp.size()-1]-temp[0]));
        return ans;
    }
};