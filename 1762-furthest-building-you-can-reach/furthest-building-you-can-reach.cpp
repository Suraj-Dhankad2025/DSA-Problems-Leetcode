class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        int i=1;
        for(i=1; i<heights.size(); i++){
            int h = heights[i] - heights[i-1];
            if(h<=0)continue;
            if(ladders==0 && h>bricks)return i-1;
            pq.push(h);
            bricks-=h;
            if(bricks<0){
                ladders--;
                bricks+=pq.top();
                pq.pop();
            }
            if(ladders<0)break;
        }
        return i-1;
    }
};