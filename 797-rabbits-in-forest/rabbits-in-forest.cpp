class Solution {
public:
    int numRabbits(vector<int>& a) {
        map<int, int>m;
        for(int i=0; i<a.size(); i++){
            m[a[i]]++;
        }
        int ans=0;
        for(auto i:m){
            int size = i.first + 1;
            int number = i.second;
            int color = (int)ceil(number*1.0/size*1.0);
            ans+=color*size;
        }
        return ans;
    }
};