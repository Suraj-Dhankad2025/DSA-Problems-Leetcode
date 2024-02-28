class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& m) {
        long long sum = 0;
        int mini=INT_MAX;
        int c=0;
        for(int i=0; i<m.size(); i++){
            for(int j=0; j<m[0].size(); j++){
                if(m[i][j]<0)c++;
                sum+=abs(m[i][j]);
                mini = min(mini, abs(m[i][j]));
            }
        }
        
        if(c%2==0)return sum;
        return sum-2*mini;
    }
};