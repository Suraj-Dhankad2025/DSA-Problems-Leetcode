class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans=0;
        int c=1;
        int ct=0;
        for (int i = 0; i < n; i++) {
            if(ct==8){
                c++;
                ct=0;
            }
            ct+=1;
            ans+=c;
        }
        return ans;
    }
};