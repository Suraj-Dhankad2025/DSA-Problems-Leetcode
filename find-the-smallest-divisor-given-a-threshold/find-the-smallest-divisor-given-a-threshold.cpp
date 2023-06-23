class Solution {
public:
    int find(vector<int>&a, int d){
        int sum=0;
        for(int i=0; i<a.size(); i++){
            sum += ceil((double)a[i]/(double)d);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int th) {
        int n = nums.size();
        int end = *max_element(nums.begin(), nums.end());
        int start = 1;
        int mid = 0;
        while(start<=end){
            mid = start + (end-start)/2;
            if(find(nums, mid)<=th){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        } 
        return start;
    }
};