class Solution {
public:
    int maxJump(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        if(n==2){
            return a[1]-a[0];
        }
        for(int i=0; i<n-2; i++){
            ans=max(ans,a[i+2]-a[i]);
        }
        return ans;
    }
};