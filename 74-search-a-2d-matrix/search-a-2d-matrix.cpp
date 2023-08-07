class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int s=0;
        int e=m-1;
        while(s<n&&e>=0){
            if(matrix[s][e]==target){
                return 1;
            }
            else if(matrix[s][e]>target){
                e--;
            }
            else{
                s++;
            }
        }
        return 0;
    }
};