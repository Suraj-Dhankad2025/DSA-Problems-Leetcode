class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        int i=0;
        for(i=0; i<heights.size()-1; i++){
            if(heights[i]>=heights[i+1]){
                continue;
            }
            if(heights[i+1]-heights[i]>bricks && ladders==0){
                return i;
            }
            int x = heights[i+1]-heights[i];
            pq.push(x);
            bricks -=x;
            if(bricks<0){
                bricks+=pq.top();
                pq.pop();
                ladders--;
            }
            if(ladders<0){
                break;
            }
        }
        return i;
    }
};