class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        map<int, int>m;
        for(auto i:costs){
            m[i]++;
        }
        int ans = 0;
        for(auto i:m){
            int cnt = i.second;
            int cost = i.first;
            int price = (long)cost*cnt;
            if(price<=coins){
                coins = coins - price;
                ans += cnt;
            }
            else{
                ans += coins/cost;
                break;
            }
        }
        return ans;
    }
};