class Solution {
public:
    vector<vector<int>>ans;
    void find(int n, int k, vector<int>&a){
        if(k==0){
            ans.push_back(a);
            return ;
        }
        if(n==0){
            return ;
        }
        a.push_back(n);
        find(n-1,k-1,a);
        a.pop_back();
        find(n-1,k,a);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>a;
        find(n, k, a);
        return ans;
    }
};