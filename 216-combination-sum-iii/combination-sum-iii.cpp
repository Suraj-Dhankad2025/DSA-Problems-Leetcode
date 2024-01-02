class Solution {
public:
    vector<vector<int>>ans;
    void find(int i,vector<int>a, int k, int n){
        if(i==10){
            if(n==0 && k==0){
                ans.push_back(a);
            }
            return ;
        }
        find(i+1, a, k,n);
        if(n>=i){
            a.push_back(i);
            find(i+1, a, k-1, n-i);
            a.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>a;
        find(1,a,k, n);
        return ans;
    }
};