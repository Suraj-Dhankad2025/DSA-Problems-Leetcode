class Solution {
public:
    int check(int mid, vector<int>& nums, vector<int>& changeIndices){
        map<int, int>m;
        for(int i=0; i<mid; i++){
            m[changeIndices[i]] = i;
        }
        if(m.size()!=nums.size())return false;
        int c=0;
        for(int i=0; i<mid; i++){
            if(i==m[changeIndices[i]]){
                if(c<nums[changeIndices[i]-1]){
                    return false;
                }
                else{
                    c = c - nums[changeIndices[i]-1];
                }
            }
            else{
                c++;
            }
        }
        return true;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int s = 0,e = changeIndices.size()+1;
        int ans = INT_MAX;
        while(s<e){
            int mid = s + (e-s)/2;
            if(check(mid, nums, changeIndices)){
                ans = min(ans, mid);
                e = mid;
            }
            else{
                s = mid+1;
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};