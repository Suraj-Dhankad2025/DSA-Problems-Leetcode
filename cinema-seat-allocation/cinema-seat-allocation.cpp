class Solution {
public:
    void isPlace(vector<int>seat, bool &l,bool &r,bool &m){
        for(int i=0;i<seat.size();i++){
            if(seat[i]>=1 && seat[i]<=4)l=false;
            if(seat[i]>=3 && seat[i]<=6)m=false;
            if(seat[i]>=5 && seat[i]<=8)r=false;
        }
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
        map<int,vector<int>>m;
        int ans=0;
        for(int i=0;i<r.size();i++){
            m[r[i][0]-1].push_back(r[i][1]-1);
        }
        int b=m.size();
        ans=(n-b)*2;
        for(auto it=m.begin(); it!=m.end();it++){
            bool l=1,r=1,m=1;
            isPlace(it->second,l,r,m);
            if(m && l && r)ans+=2;
            else if(!l && !r && m)ans+=1;
            else if(l || m || r)ans+=1;
        }
        return ans;     
    }
};