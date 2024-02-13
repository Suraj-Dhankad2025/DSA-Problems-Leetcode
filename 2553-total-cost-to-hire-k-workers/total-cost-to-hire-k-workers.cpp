class Solution {
public:
    int max(int a, int b){
        if(a>b)return a;
        return b;
    }
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>>pq1;
        priority_queue<int, vector<int>, greater<int>>pq2;
        for(int i=0; i<candidates; i++){
            pq1.push(costs[i]);
        }
        for(int i=max(candidates, costs.size() - candidates); i<costs.size(); i++){
            pq2.push(costs[i]);
        }
        int nextHead = candidates;
        int nextTail = costs.size() - 1 - candidates;
        long long ans = 0;
        for(int i=0; i<k; i++){
            if(pq2.size()==0 || !pq1.empty() && pq1.top()<=pq2.top()){
                ans+=pq1.top();
                pq1.pop();
                if(nextHead<=nextTail){
                    pq1.push(costs[nextHead]);
                    nextHead++;
                }
            }
            else{
                ans+=pq2.top();
                pq2.pop();
                if(nextHead<=nextTail){
                    pq2.push(costs[nextTail]);
                    nextTail--;
                }
            }
        }
        return ans;
    }
};