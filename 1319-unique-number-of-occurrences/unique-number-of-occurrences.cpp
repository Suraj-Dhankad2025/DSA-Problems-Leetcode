class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int>m1;
        map<int, int>m2;
        for(auto i:arr){
            m1[i]++;
        }
        for(auto i:m1){
            if(m2[i.second]!=0){
                return false;
            }
            m2[i.second]++;
        }
        return true;
    }
};