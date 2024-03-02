class Solution {
public:
    int mod = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0;
        int pre = 0;
        int odd=0,even=0;
        vector<int>sum;
        for(auto i:arr){
            pre += i;
            if(pre%2==1){
                ans++;
                odd++;
                ans = (ans + even)%mod;
            }
            else{
                even++;
                ans = (ans + odd)%mod;
            }
        }
        return ans%mod;
    }
};