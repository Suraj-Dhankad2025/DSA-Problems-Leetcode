class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = k;
        int x=0;
        int ans = 0;
        for(int i=0; i<32; i++){
            x = 0;
            for(int j=0; j<nums.size(); j++){
                int bit = (1<<i) & nums[j];
                x=x^bit;
            }  
            int bitVal = (1<<i) & k;
            if(x!=bitVal){
                ans++;
            }
        }
        return ans;
    }
};