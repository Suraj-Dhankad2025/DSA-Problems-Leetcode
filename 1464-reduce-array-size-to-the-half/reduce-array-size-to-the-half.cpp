class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>m;
        for(int i=0; i<n; i++){
            m[arr[i]]++;
        }
        priority_queue<pair<int, int>>pq;
        for(auto i:m){
            pq.push({i.second, i.first});
        }
        int j=0,ans=0;
        while(!pq.empty()){
            int f = pq.top().first;
            pq.pop();
            j+=f;
            ans++;
            if(j>=n/2){
                break;
            }
        }
        return ans;
    }
};