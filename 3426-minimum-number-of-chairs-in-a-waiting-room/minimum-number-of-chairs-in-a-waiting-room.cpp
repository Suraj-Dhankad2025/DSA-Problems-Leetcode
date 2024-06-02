class Solution {
public:
    int find(int chair, string s){
        for(auto i:s){
            if(i=='E'){
                chair--;
            }
            if(i=='L'){
                chair++;
            }
            if(chair<0){
                return 0;
            }
        }
        return 1;
    }
    int minimumChairs(string st) {
        int s=0,e=st.size();
        int ans = 0;
        while(s<e){
            int mid = s + (e-s)/2;
            if(find(mid, st)==1){
                e = mid;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
};