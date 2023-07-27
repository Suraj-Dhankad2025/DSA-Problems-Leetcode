class Solution {
public:
    bool check(long long int t, vector<int>&b, int n){
        long long int totalTime=0;
        
        for(long long bTime:b){
            if(bTime<t){
                totalTime += bTime;
            }
            else{
                totalTime+=t;
            }
        }
        return (totalTime>=n*t);
    }
    long long maxRunTime(int n, vector<int>& b) {
        if(b.size()<n){
            return 0;
        }
        long long int s = *min_element(b.begin(), b.end());
        long long int e = accumulate(b.begin(), b.end(), 0LL)/n;
        long long int ans=0;
        while(s<=e){
            long long int mid = s + (e-s)/2;
            if(check(mid,b,n)){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
};