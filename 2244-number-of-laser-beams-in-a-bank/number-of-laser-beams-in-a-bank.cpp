class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        vector<int>v;
        for(auto s:bank){
            int device = 0;
            for(auto i:s){
                if(i=='1'){
                    device++;
                }
            }
            v.push_back(device);
        }
        for(int i=0; i<v.size(); i++){
            int j=i+1;
            int c=0;
            while(j<v.size()){
                if(c>0)break;
                c+=v[i]*v[j];
                j++;
            }
            ans+=c;
        }
        return ans;
    }
};