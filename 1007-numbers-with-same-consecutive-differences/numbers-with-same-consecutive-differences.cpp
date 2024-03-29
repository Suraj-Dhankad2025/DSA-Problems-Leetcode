class Solution {
public:
    void dfs(int num, int n, int k, vector<int>&ans){
        if(n==0){
            ans.push_back(num);
            return ;
        }
        int lastDigit = num%10;
        if(lastDigit-k>=0){
            dfs(num*10 + lastDigit-k, n-1, k, ans);
        }
        if(k!=0 && lastDigit+k<=9){
            dfs(num*10 + lastDigit+k, n-1, k, ans);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        for(int i=1; i<=9; i++){
            dfs(i, n-1, k, ans);
        }
        return ans;
    }
};