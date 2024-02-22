class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
        vector<int>a(n+1, 0);
        vector<int>b(n+1, 0);
        for(int i=0; i<t.size(); i++){
            a[t[i][0]]++;
            b[t[i][1]]++;
        }
        for(int i=1; i<n+1; i++){
            if(a[i]==0 && b[i]==n-1)return i;
        }
        return -1;
    }
};