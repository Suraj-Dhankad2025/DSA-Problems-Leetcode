class Solution {
public:
    int ans = 0;
    int find(int i, vector<int>& cost, int n){
        if(i>=n){
            return 0;
        }
        int l = find(i*2 + 1, cost, n);
        int r = find(i*2 + 2, cost, n);
        ans += abs(l-r);
        return cost[i] + max(l, r);
    }
    int minIncrements(int n, vector<int>& cost) {
        find(0, cost, n);
        return ans;
    }
};