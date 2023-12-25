class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int mod=1e9+7;
        unordered_set<int>s1,s2;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        for(int i=0; i<hFences.size(); i++){
            for(int j=i+1; j<hFences.size(); j++){
                s1.insert(hFences[j]-hFences[i]);
            }
        }
        for(int i=0; i<vFences.size(); i++){
            for(int j=i+1; j<vFences.size(); j++){
                s2.insert(vFences[j]-vFences[i]);
            }
        }
        long long ans=0;
        for(auto i:s1){
            if(s2.find(i)!=s2.end()){
                long long x = (long long)i*i;
                if(x>ans)ans = x;
            }
        }
        if(ans==0)return -1;
        ans = ans%mod;
        return ans;
    }
};