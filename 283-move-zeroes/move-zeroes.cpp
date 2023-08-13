class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        queue<int>q;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0)q.push(nums[i]);
        }
        int j=q.size();
        for(int i=0; i<j; i++){
            nums[i] = q.front();
            q.pop();
        }
        
        while(j<nums.size()){
            nums[j] = 0;
            j++;
        }
        return ;
    }
};