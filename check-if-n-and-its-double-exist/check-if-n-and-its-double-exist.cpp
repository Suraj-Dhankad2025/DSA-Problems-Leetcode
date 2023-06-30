class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // unordered_map<int, int>m;
        // for(int i=0; i<arr.size(); i++){
        //     m[arr[i]]++;
        // }
        // for(int i=0; i<arr.size(); i++){
        //     int t = 2*arr[i];
        //     if(m.find(t)!=m.end()){
        //         return true;
        //     }
        // }
        int n = arr.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[j]==2*arr[i] && i!=j){
                    return true;
                }
            }
        }
        return false;
    }
};