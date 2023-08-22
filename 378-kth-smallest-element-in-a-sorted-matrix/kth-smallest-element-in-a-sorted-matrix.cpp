class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;
        for(int i=0; i<n; i++){
            pq.push({matrix[i][0], {i,0}});
        }
        int ans = -1;
        while(!pq.empty()){
            int x = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            k--;
            if(r<n && c<m-1)pq.push({matrix[r][c+1],{r,c+1}});
            if(k==0){
                ans=x;
                break;
            }
        }
        return ans;
    }
};