class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>pre(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int top = i>0 ? pre[i-1][j]: 0;
                int left = j>0 ? pre[i][j-1]: 0;
                int topleft = (i>0 && j>0) ? pre[i-1][j-1]: 0;
                pre[i][j] += mat[i][j] + top + left - topleft;
            }
        }
        int ans=0;
        for(int r1=0; r1<n; r1++){
            for(int r2=r1; r2<n; r2++){
                map<int, int>mp;
                mp[0] = 1;
                int curSum = 0;
                for(int c=0; c<m; c++){
                    curSum = pre[r2][c];
                    if(r1>0){
                        curSum = curSum - pre[r1-1][c];
                    }
                    int dif = curSum - target;
                    if(mp.find(dif)!=mp.end()){
                        ans+=mp[dif];
                    }
                    mp[curSum]++;
                }
            }
        }
        return ans;
    }
};