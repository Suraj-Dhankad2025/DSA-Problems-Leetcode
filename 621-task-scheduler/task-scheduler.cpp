class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time=0;
        unordered_map<int, int>m;
        priority_queue<int>pq;
        queue<pair<int, int>>q;
        for(int i=0; i<tasks.size(); i++){
            m[tasks[i]]++;
        }
        for(auto i:m){
            pq.push(i.second);
        }
        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
                int f = pq.top();
                pq.pop();
                if(f-1>0){
                    q.push({time + n, f-1});
                }
            }
            if(time==q.front().first){
                pq.push(q.front().second);
                q.pop();
            }
        }
        return time;
    }
};