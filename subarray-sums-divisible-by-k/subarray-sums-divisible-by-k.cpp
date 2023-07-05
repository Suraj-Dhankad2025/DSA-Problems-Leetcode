class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int K) {
        // int sum=0;
        // int ans=0;
        // int n =nums.size();
        // unordered_map<int, int>m;
        // m[0]++;
        // for(int i=0; i<n; i++){
        //     sum+=nums[i];
        //     sum=((sum)%k + k)%k;
        //     ans+=m[sum];
        //     m[sum]++;
        // }
        // return ans;
        int N=arr.size();
        vector<int>mp(K,0);
	    int rem=0;
	    mp[0]++;
	    int sum=0;
	    int cnt=0;
	    for(int i=0;i<N;i++){
	        sum+=arr[i];
	        rem=sum%K;
	        if(rem<0){
	            rem=rem+K;
	        }
	        if(mp[rem]!=0){
	            cnt+=mp[rem];
	        }
	        mp[rem]++;
	    }
	    return cnt;
    }
};