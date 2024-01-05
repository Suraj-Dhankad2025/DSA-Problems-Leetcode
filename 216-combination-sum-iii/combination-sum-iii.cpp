class Solution {
public:
    vector<vector<int>>ans;
    void find(int num, vector<int>temp, int sum, int k){
        if(num==10){
            if(k==0 && sum==0){
                ans.push_back(temp);
            }
            return ;
        }
        find(num+1, temp, sum, k);
        if(sum>=num){
            temp.push_back(num);
            find(num+1, temp, sum-num, k-1);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        find(1, temp, n, k);
        return ans;
    }
};