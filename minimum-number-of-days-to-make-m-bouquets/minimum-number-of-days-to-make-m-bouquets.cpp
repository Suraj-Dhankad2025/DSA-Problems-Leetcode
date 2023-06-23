class Solution {
public:
    int find(vector<int>&a, int day, int size){
        int count=0;
        int bouquets=0;
        for(int i=0; i<a.size(); i++){
            if(day>=a[i]){
                count++;
            }
            else{
                bouquets += count/size;
                count=0;
            }
        }
        bouquets += count/size;
        return bouquets;
    }
    int minDays(vector<int>& bloom, int m, int k) {
        int n = bloom.size();
        if((long long )m*k>n)return -1;
        int end = *max_element(bloom.begin(), bloom.end());
        int start = *min_element(bloom.begin(), bloom.end());
        int mid = 0;
        while(start<=end){
            mid = start + (end-start)/2;
            if(find(bloom, mid, k)>=m){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
};