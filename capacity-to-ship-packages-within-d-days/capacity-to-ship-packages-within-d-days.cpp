class Solution {
public:
    int find(vector<int>&v, int cap){
        int day=1;
        int load = 0;
        for(int i=0; i<v.size(); i++){
            if(load + v[i]>cap){
                day+=1;
                load = v[i];
            }
            else{
                load+=v[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& w, int days) {
        
        int s = INT_MIN;
        int e = 0;
        for(int i=0; i<w.size(); i++){
            e+=w[i];
            s = max(s, w[i]);
        }
        while(s<=e){
            int mid = s + (e-s)/2;
            if(find(w, mid)<=days){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
};