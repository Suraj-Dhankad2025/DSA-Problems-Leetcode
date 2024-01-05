class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n =nums.size();
        set<vector<int>>s;
        vector<int>temp;
        int c = 0;
        for(int i=0; i<n; i++){
            temp.clear();
            c=0;
            for(int j=i; j<n; j++){
                temp.push_back(nums[j]);
                if(nums[j]%p==0){
                    c++;
                }
                if(c>k){
                    break;
                }
                s.insert(temp);
            }
        }
        return s.size();
    }
};