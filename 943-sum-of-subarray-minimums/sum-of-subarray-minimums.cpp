class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        stack<int> st;
        vector<int> dp(n, 0);
        int sum = 0;
        for(int i =0 ;i < n ; i ++ ){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()){
                dp[i] = (i+1)*arr[i];
            }else{
                dp[i] = dp[st.top()] + (i - st.top())*arr[i];
            }
            sum = (sum + dp[i])%mod;
            st.push(i);
        }
        return sum;
    }
};