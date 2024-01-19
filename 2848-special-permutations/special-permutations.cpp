
// const int MOD = 1e9 + 7;
// class Solution {
// public:
//     int find(const vector<int>& nums, int prev, int index, int mask, vector<vector<int>>& dp) {
//         if (index == nums.size()) {
//             return 1;
//         }
//         if (dp[prev + 1][mask] != -1) {
//             return dp[prev + 1][mask];
//         }
//         int total = 0;
//         for (int i = 0; i < nums.size(); ++i) {
//             if (!(mask & (1 << i)) && (prev == -1 || nums[i] % nums[prev] == 0 || nums[prev] % nums[i] == 0)) {
//                 total = (total + find(nums, i, index + 1, mask | (1 << i), dp)) % MOD;
//             }
//         }
//         dp[prev + 1][mask] = total;
//         return total;
//     }
//     int specialPerm(const vector<int>& nums) {
//         vector<vector<int>> dp(nums.size() + 1, vector<int>((1 << nums.size()), -1));
//         return find(nums, -1, 0, 0, dp);
//     }
// };
class Solution {
    int n;
    vector<vector<int>> graph;
    vector<vector<int>> record;
    int Mod=1e9+7;
public:
    int specialPerm(vector<int>& nums) {
        n=nums.size();
        graph.resize(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]%nums[j]==0||nums[j]%nums[i]==0){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        record.resize(n,vector<int>(1<<n,-1));
        int ret=0;
        for(int i=0;i<n;i++){
            ret+=dfs(0,i,1<<i);
            ret%=Mod;
        }
        return ret;
    }
    int dfs(int cnt, int cur, int state){
        if(cnt==n-1)
            return 1;
        if(record[cur][state]!=-1)
            return record[cur][state];
        int ret=0;
        for(int nxt:graph[cur]){
            if((state>>nxt)&1)
                continue;
            ret+=dfs(cnt+1,nxt,state+(1<<nxt));
            ret%=Mod;
        }
        record[cur][state]=ret;
        return ret;
    }
};