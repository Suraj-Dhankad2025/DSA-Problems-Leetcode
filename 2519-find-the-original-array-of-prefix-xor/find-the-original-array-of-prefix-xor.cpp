class Solution {
public:
    vector<int> findArray(vector<int>& pre) {
        vector<int>ans;
        for(int i=pre.size()-1; i>0; i--){
            int num = pre[i]^pre[i-1];
            ans.push_back(num);
        }
        ans.push_back(pre[0]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};