class Solution {
public:
    int mySqrt(int x) {
        int i=1;
        int j = x;
        long long int mid = -1;
        long long int ans = 0;
        if(x==0||x==1)return x;
        while(i<=j){
             mid = i + (j-i)/2;
            if(mid*mid<=x){
                ans = mid;
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        return j;
    }
};