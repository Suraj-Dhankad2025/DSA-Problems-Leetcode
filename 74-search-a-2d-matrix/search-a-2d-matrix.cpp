class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int s = 0;
        int e = m-1;
        while(s<n && e>=0){
            if(mat[s][e]==target){
                return true;
            }
            else if(mat[s][e]>target){
                e--;
            }
            else{
                s++;
            }
        }
        return false;
    }
};