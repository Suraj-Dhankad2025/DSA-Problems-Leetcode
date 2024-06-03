class Solution {
public:
    int minimumChairs(string s) {
        int ans = INT_MIN;
        int x=0;
        for(auto i:s){
            if(i=='E'){
                x++;
            }
            else{
                x--;
            }
            ans = max(ans, x);
        }
        return ans;
    }
};