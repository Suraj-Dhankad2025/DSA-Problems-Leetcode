class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=0;
        int j = num;
        while(i<=j){
            long long int mid = i + (j-i)/2;
            if(mid*mid<num){
                i = mid+1;
            }
            else if(mid*mid>num){
                j = mid-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};