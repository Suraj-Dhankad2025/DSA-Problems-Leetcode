class Solution {
public:
    long long help(vector<int>&piles,int t){
        long long totaltime = 0;
        for(int i=0;i<piles.size();i++){
            totaltime += ceil((double)(piles[i])/(double)(t));
        }
        return totaltime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for(int i=0;i<piles.size();i++){
            if(piles[i]>maxi)
                maxi = piles[i];
        }
        int low = 1;
        int high = maxi;
        int res = INT_MAX;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(help(piles,mid)<=h){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
};