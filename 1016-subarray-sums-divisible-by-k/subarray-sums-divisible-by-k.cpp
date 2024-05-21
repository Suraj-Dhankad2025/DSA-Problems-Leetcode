class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int>m;
        int ans=0;
        m[0]++;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            int rem = sum%k;
            if(rem<0){
                rem+=k;
            }
            if(m.find(rem)!=m.end()){
                ans+=m[rem];
            }
            m[rem]++;
        }
        return ans;
    }
};