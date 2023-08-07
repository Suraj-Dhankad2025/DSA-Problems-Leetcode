class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int size = m*n;
        int s=0;
        int e=size-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            int r = mid/m;
            int c = mid%m;
            if(matrix[r][c]==target){
                return 1;
            }
            if(matrix[r][c]>target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return 0;
    }
};