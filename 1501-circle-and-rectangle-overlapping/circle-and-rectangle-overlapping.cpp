class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int dis = 0;
        for(int i=x1; i<=x2; i++){
            for(int j=y1; j<=y2; j++){
                dis = (xCenter - i)*(xCenter - i) + (yCenter - j)*(yCenter - j);
                if(dis<=radius*radius){
                    return true;
                }
            }
        }
        return false;
    }
};