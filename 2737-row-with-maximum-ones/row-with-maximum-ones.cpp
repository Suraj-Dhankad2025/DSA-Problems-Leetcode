class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int ans=0;
        int k=0;
        for(int i=0; i<mat.size(); i++){
            int c=0;
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j]==1){
                    c++;
                }
            }
            if(c>ans){
                k=i;
                ans=c;
            }
        }
        return {k, ans};
    }
};