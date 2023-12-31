class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        if(special.size()==0){
            return top - bottom + 1;
        }
        int ans=0;
        sort(special.begin(),special.end());
        ans= max(ans,special[0]-bottom);
        bottom= special[0];
        for (int i=1; i<special.size(); i++){
            ans= max(ans,special[i]-bottom-1);
            bottom= special[i];
        }
        ans= max(ans,top-bottom);
        return ans;
    }
};