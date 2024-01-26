class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto i:asteroids){
            pq.push(i);
        }
        int maxi = *max_element(asteroids.begin(), asteroids.end());
        while(!pq.empty()){
            int a = pq.top();
            pq.pop();
            if(mass>=a){
                if(mass>=maxi)continue;
                mass+=a;
                
            }
            else{
                return false;
            }
        }
        return true;
    }
};