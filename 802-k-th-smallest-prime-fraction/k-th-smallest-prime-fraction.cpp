class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>>pq;
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                double x = 1.0000*arr[i]/arr[j];
                pq.push({x,{i,j}});
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        int a = arr[pq.top().second.first];
        int b = arr[pq.top().second.second];
        return {a,b};
    }
};