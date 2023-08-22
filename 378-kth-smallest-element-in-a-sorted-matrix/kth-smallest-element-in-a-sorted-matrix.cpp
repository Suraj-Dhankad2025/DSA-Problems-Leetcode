class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        // priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;
        // for(int i=0; i<k; i++){
        //     pq.push({matrix[i][0], {i,0}});
        // }
        // int ans = -1;
        // while(!pq.empty()){
        //     int x = pq.top().first;
        //     int r = pq.top().second.first;
        //     int c = pq.top().second.second;
        //     pq.pop();
        //     k--;
        //     pq.push({matrix[r][c+1],{r,c+1}});
        //     if(k==0){
        //         ans=x;
        //         break;
        //     }
        // }
        // return ans;
        priority_queue<int>pq;
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                pq.push(matrix[i][j]);
                if(pq.size()> k )
                {
                    pq.pop();
                }
            
            }
        }
        
        return pq.top();        
    }
};