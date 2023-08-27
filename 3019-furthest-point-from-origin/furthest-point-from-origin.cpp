class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int movesr=0;
        int under=0;
        int movesl=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L'){
                movesl++;
            }
            else if(moves[i]=='R'){
                movesr++;
            }
            else{
                under++;
            }
        }
        if(movesl>=movesr){
            return movesl-movesr+under;
        }
        return movesr-movesl+under;
    }
};