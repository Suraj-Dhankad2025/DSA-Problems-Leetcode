class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num1<num2){
            return -1;
        }
        for(int k=0; k<=32; k++){
            long long int dif = num1 - (long long)k*num2;
            int bits = __builtin_popcountll(dif);
            // int n = dif;
            // while(n){
            //     if(n%2!=0){
            //         bits++;
            //     }
            //     n = n/2;
            // }
            if(bits<=k && k<=dif){
                return k;
            }
        }
        return -1;
    }
};