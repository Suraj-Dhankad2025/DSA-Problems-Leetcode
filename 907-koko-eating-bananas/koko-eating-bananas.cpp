class Solution {
public:
    long long find(int s, vector<int>&piles){
        long long time = 0;
        for(int i=0; i<piles.size(); i++){
            int q = piles[i];
            time += q/s;
            if(q%s!=0){
                time++;
            }
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(find(mid, piles)<=h){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};