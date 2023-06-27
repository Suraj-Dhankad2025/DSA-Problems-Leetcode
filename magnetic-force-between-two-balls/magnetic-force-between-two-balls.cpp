class Solution {
public:
    int find(vector<int>&v, int mid){
        int balls=1;
        int last=v[0];
        for(int i=1; i<v.size(); i++){
            if(v[i] - last >= mid){
                balls++;
                last = v[i];
            }
        }
        return balls;
    }
    int maxDistance(vector<int>& p, int m) {
        int s = 1;
        sort(p.begin(), p.end());
        int e = *max_element(p.begin(), p.end()) - *min_element(p.begin(), p.end());
        while(s<=e){
            int mid = s + (e-s)/2;
            if(find(p, mid)>=m){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return e;
    }
};