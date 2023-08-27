class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r=0;
        int x=0;
        int l=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L'){
                l++;
            }
            else if(moves[i]=='R'){
                r++;
            }
            else{
                x++;
            }
        }
        return abs(r-l)+x;
    }
};