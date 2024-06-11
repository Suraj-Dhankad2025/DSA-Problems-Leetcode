class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int ans = 0;
        int c=0;
        for(int i=1; i<skills.size(); i++){
            if(skills[ans]>skills[i]){
                c++;
            }
            else{
                ans = i;
                c = 1;
            }
            if(c==k){
                return ans;
            }
        }
        return ans;
    }
};