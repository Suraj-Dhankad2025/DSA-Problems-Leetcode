class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int>s;
        for(int i=0; i<n; i++){
            while(!s.empty() && nums[i]<nums[s.top()] && s.size()+n-i-1>=k){
                s.pop();
            }
             s.push(i);
        }
        while(s.size()>k){
            s.pop();
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(nums[s.top()]);
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};