class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> res = nums;
        sort(res.begin(),res.end());
        vector<int> bits(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int count = 0;
            while (num) {
                count += num & 1;
                num >>= 1;
            }
            bits[i] = count;
        }
        int bit = bits[0];
        int bitIndex = 0;
        
        for(int i=1;i<bits.size();i++){
            if(bit == bits[i]) continue;
            else{
                sort(nums.begin()+bitIndex,nums.begin()+i);
                bitIndex = i;
                bit = bits[i];
            }
        }
        
        sort(nums.begin()+bitIndex,nums.end());
       
        return res == nums;
    }
};