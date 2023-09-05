class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n = mat.size();
        int m = mat[0].size();
        int s = 0;
        int e = m-1;
        while(s<n && e>=0){
            if(mat[s][e]==t){
                return true;
            }
            else if(mat[s][e]>t){
                e--;
            }
            else{
                s++;
            }
        }
        return false;
    }
};