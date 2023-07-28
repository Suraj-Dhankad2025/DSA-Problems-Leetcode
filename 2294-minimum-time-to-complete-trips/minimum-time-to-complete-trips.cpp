class Solution {
public:
    bool find(vector<int>&time, int tt, int mid){
        long long int sum=0;
        for(int i=0; i<time.size(); i++){
            sum+=(long long )mid/time[i];
        }
        if(sum>=tt)return true;
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        // // if(n==1){
        // //     return time[0]*totalTrips;
        // // }
        // sort(time.begin(), time.end());
        long long int s = 0,e=(long long)time[n-1]*totalTrips;
        long long int mid;
        long long int ans = e;
        while(s<=e){
            mid = s + (e-s)/2;
            long long sum = 0;
            for(int i=0; i<time.size(); i++){
                sum+=(long long )(mid/time[i]);
            }
            if(sum>=totalTrips){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};