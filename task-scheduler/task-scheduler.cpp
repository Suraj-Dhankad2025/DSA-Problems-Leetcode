class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        queue<pair<int, int>>q;
        map<char , int>m;
        for(int i=0; i<tasks.size(); i++){
            m[tasks[i]]++;
        }
        for(auto i:m){
            pq.push(i.second);
        }
        int time = 0;
        while(!q.empty()||!pq.empty()){
            time+=1;
            if(!pq.empty()){
                int freq = pq.top();
                pq.pop();
                freq = freq-1;
                if(freq!=0){
                    q.push({time+n,freq});
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