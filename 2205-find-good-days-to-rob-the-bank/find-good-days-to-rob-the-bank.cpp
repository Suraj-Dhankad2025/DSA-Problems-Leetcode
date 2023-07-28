class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int t) {
        int n = s.size();
        vector<int>v1(n,0);
        // v1[0]=1;
        for(int i=1; i<n; i++){
            if(s[i-1]>=s[i]){
                v1[i] = v1[i-1]+1;
            }
        }
        vector<int>v2(n,0);
        for(int i=n-2; i>=0; i--){
            if(s[i]<=s[i+1]){
                v2[i] = v2[i+1]+1;
            }
        }
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(v1[i]>=t && v2[i]>=t){
                ans.push_back(i);
            }
        }
        return ans;
    }
};