class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int mod = 1e9+7;
        int n = nums.size();
        stack<int>st;
        vector<int>nse;

        for(int i=nums.size()-1; i>=0; i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                nse.push_back(st.top());
            }
            else{
                nse.push_back(-1);
            }
            st.push(i);
        }
        reverse(nse.begin(), nse.end());
        stack<int>st1;
        vector<int>pse;
        for(int i=0; i<nums.size(); i++){
            while(!st1.empty() && nums[st1.top()]>=nums[i]){
                st1.pop();
            }
            if(!st1.empty()){
                pse.push_back(st1.top());
            }
            else{
                pse.push_back(-1);
            }
            st1.push(i);
        }
        long long ans=0;
        vector<long long>prefixSum(n);
        prefixSum[0]=nums[0];
        for(int i=1; i<nums.size(); i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        for(int i=0; i<nums.size(); i++){
            long long s=0;
            if(nse[i]==-1){
                s=prefixSum.back();
            }
            else{
                s=prefixSum[nse[i]-1];
            }
            if(pse[i]!=-1){
                s-=prefixSum[pse[i]];
            }
            ans=max(ans,s*(long long)nums[i]);
        }
        return ans%mod;
    }
};