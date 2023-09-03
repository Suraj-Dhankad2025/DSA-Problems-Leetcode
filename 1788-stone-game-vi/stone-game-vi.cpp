class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        priority_queue<pair<int, int>>pq;
        for(int i=0; i<a.size(); i++){
            pq.push({a[i]+b[i], i});
        }
        bool f=0;
        int alice=0,bob=0;
        while(!pq.empty()){
            int x = pq.top().second;
            pq.pop();
            if(f==0){
                f=1;
                alice+=a[x];
            }
            else{
                f=0;
                bob+=b[x];
            }
        }
        if(alice>bob){
            return 1;
        }
        else if(bob>alice){
            return -1;
        }
        else{
            return 0;
        }
    }
};