class Solution {
public:
    int pivotInteger(int n) {
        int sum1 = n*(n+1)/2;
        int sum2 = 0;
        int ans = -1;
        for(int i=1; i<=n; i++){
            sum2+=i;
            if(sum1==sum2){
                ans = i;
                break;
            }
            sum1-=i;
        }
        return ans;
    }
};