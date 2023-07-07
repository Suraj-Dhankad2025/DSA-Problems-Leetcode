class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int>m;
        int n = nums.size();
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        for(int i=0; i<1e9; i++){
            if(m.find(i+1)==m.end()){
                return i+1;
            }
        }
        
        return -1;
    }
};