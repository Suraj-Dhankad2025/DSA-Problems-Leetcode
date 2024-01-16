#define ll long long
// ll bitSum[100];
class Solution {
public:
    // void findBitSum(ll n){
    //     if(n==0) return;
    //     if(n==1){
    //         bitSum[0]++;
    //         return;
    //     }
    //     if(n==2){
    //         bitSum[0]++;
    //         bitSum[1]++;
    //         return;
    //     }

    //     ll mostSignificantBit = log2(n);
    //     ll cn = (1ll<<mostSignificantBit);
    //     bitSum[mostSignificantBit] += n-cn+1;
    //     for(ll i=0; i<mostSignificantBit; i++){
    //         bitSum[i] += cn/2;
    //     } 
    //     findBitSum(n-cn);
    // }
    bool isPricePossible(long long a,long long k,int x){
        long long cost = 0;
        for(int i = 0; i <= 54 ; i++){
            if((1+i)%x == 0){
                long long power = 1ll << (i+1);
                cost += ((a + 1)/power)*(power/2);
                cost += max(0ll,((a + 1)%power - power/2));
            }
        }
        if(cost <= k) return true;
        return false;
    }
    long long findMaximumNumber(long long k, int x) {
        ll s = 0;
        ll e = 1e15;
        ll mid = 0, ans=0;
        while(s<=e){
            mid = s + (e-s)/2;
            // memset(bitSum, 0, sizeof(bitSum));
            // findBitSum(mid);
            // ll sum=0;
            // for(int i=0; i<53; i++){
            //     if((i+1)%x==0){
            //         sum+=bitSum[i];
            //     }
            // }
            if(isPricePossible(mid, k,x)){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return ans;
    }
};