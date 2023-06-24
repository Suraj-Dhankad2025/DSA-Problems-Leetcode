class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = -1;
        int j=0;
        unordered_map<int, int>m;
        for(auto i:arr){
            m[i]++;
        }
        for(int i=1; i<=k+arr.size(); i++){
            if(m.find(i)==m.end()){
                j++;
            }
            if(j==k)return i;
        }
        return -1;
    }
};