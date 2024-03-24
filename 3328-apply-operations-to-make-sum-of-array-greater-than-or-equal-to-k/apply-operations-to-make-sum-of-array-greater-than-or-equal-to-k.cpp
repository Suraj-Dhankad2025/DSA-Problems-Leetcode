class Solution {
public:
    int minOperations(int k) {
        int ans = 1e9;
        for(int i=0; i<k ;i++){
            int n = 1+i;
            int x = (k/n);
            if(k%n!=0){
                x++;
            }
            ans = min(ans, i+x);
        }
        return --ans;
    }
};