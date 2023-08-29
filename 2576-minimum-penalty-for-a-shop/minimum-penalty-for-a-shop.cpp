class Solution {
public:
    int bestClosingTime(string a) {
        vector<int>yes;
        vector<int>no;
        int noY=0;
        int noN=0;
        for(int i=a.size()-1; i>=0; i--){
            if(a[i]=='Y'){
                noY++;
            }
        }
        for(int i=0; i<a.size(); i++){
            no.push_back(noN);
            if(a[i]=='N'){
                noN++;
            }
            yes.push_back(noY);
            if(a[i]=='Y'){
                noY--;
            }
        }
        yes.push_back(noY);
        no.push_back(noN);
        int ans=INT_MAX;
        int res=-1;
        for(int i=0; i<=a.size(); i++){
            int p = yes[i] + no[i];
            if(p<ans){
                ans = p;
                res = i;
            }
        }
        // if(res==a.size()-1 && a[a.size()-1]=='Y')return a.size();
        return res;
    }
};