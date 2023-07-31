class Solution {
public:
    bool closeStrings(string w1, string w2) {
        if(w1.length()!=w2.length())return false;
        int n = w1.length();
        vector<int>v1(26, 0);
        vector<int>v2(26, 0);
        vector<int>v3(26, 0);
        vector<int>v4(26, 0);
        for(int i=0; i<n; i++){
            v1[w1[i]-'a']=1;
            v2[w2[i]-'a']=1;
        }
        for(int i=0; i<n; i++){
            v3[w1[i]-'a']++;
            v4[w2[i]-'a']++;
        }
        
        sort(v3.begin(), v3.end());
        sort(v4.begin(), v4.end());
        if(v1==v2 && v3==v4)return true;
        return false;
    }
};