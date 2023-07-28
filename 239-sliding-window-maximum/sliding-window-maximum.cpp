class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>d;
        int i=0; 
        int j=0;
        vector<int>ans;
        while(j<nums.size()){
            while(!d.empty() && nums[j]>d.back()){
                d.pop_back();
            }
            d.push_back(nums[j]);
            if(j-i+1==k){
                ans.push_back(d.front());
                if(d.front()==nums[i]){
                    d.pop_front();
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};