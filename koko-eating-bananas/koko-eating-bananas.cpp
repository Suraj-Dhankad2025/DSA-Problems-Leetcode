class Solution {
public: 
    long long int find(vector<int>&p, int speed){
        long long int time = 0;
        for(int i=0; i<p.size(); i++){
            // time = time + ceil((double)p[i]/(double)speed);
            time = time + (p[i]/speed);
            if(p[i]%speed!=0){
                time++;
            }
        }
        return time;
    }
    int minEatingSpeed(vector<int>& p, int h) {
        int s = 1;
        int e = *max_element(p.begin(), p.end());
        // cout<<e;
        while(s<=e){
            int mid = s + (e-s)/2;
            long long int time = find(p,mid);
            if(time<=h){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
};