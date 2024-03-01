class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        for(int i=0; i<costs.size(); i++){
            if(coins<0){
                return ans-1;
            }
            coins -= costs[i];
            ans++;
        }
        if(coins<0){
            return ans-1;
        }
        return ans;
    }
};