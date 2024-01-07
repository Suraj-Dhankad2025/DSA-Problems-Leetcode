class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        int count=0;
        char prev=s[0];
        int ans=-1;
        string str="";
        map<string,int>mp;
        for(int i=0;i<n;i++){
            if(s[i]==prev){
                str+=s[i];
            }
            else{
                mp[str]++;
                str="";
                prev=s[i];
                str+=s[i];
            }
        }
        mp[str]++;
        for(auto it:mp){
            int sz=it.first.size();
            int f=it.second;
            string sp=it.first;
            if(f>=3){
                ans=max(ans,sz);
            }
            if(f==2){
                ans=max(ans,sz-1);
            }
            if(f==1){
                sp.pop_back();
                if((mp[sp]+2)>=3){
                    ans=max(ans,sz-1);
                }
                ans=max(ans,sz-2);
            }
        }
        if(ans==0){
            return -1;
        }
        return ans;
    }
};