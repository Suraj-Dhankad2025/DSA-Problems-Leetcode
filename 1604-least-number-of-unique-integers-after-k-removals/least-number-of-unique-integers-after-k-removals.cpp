class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int>m;
        for(auto i:arr){
            m[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        
        for(auto i:m){
            pq.push({i.second, i.first});
        }
        while(!pq.empty() && k>0){
            auto [f, e] = pq.top();
            pq.pop();
            if(f-1>0){
                pq.push({f-1, e});
            }
            k--;
        }
        return pq.size();
    }
};