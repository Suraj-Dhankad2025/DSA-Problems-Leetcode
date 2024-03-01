class Solution {
public:
    bool check(string &s){
        vector<int>v(26, 0);
        for(auto i:s){
            v[i-'a']++;
            if(v[i-'a']>1){
                return false;
            }
        }
        return true;
    }
    int find(int i, vector<string>& arr, string s, unordered_map<string, int>&dp){
        if(i>=arr.size()){
            if(check(s)){
                return s.size();
            }
            return -1e9;
        }
        if(dp.find(s)!=dp.end()){
            return dp[s];
        }
        int notTake = find(i+1, arr, s, dp);
        int take = find(i+1, arr, s+arr[i], dp);
        return dp[s] = max(take, notTake);
    }
    int maxLength(vector<string>& arr) {
        unordered_map<string, int>dp;
        return find(0, arr, "", dp);
    }
};