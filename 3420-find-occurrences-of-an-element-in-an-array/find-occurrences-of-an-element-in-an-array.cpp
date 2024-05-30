class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int>ans;
        vector<int>f;
        int c=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==x){
                c++;
            }
            f.push_back(c);
        }
        for(auto i:queries){
            int s = 0, e = f.size()-1;
            int res = -1;
            while(s<=e){
                int mid = s + (e-s)/2;
                if(f[mid]==i){
                    res = mid;
                    e = mid-1;
                }
                else if(f[mid]>i){
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};