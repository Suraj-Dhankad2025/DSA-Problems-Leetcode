class Solution {
public:
    vector<vector<string>>ans;
    bool isPallindrome(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])return 0;
            i++;
            j--;
        }
        return 1;
    }
    void find(int i, string s, vector<string>&v){
        if(i==s.size()){
            ans.push_back(v);
            return ;
        }
        for(int j=i; j<s.size(); j++){
            string st = s.substr(i, j-i+1);
            if(isPallindrome(st)){
                v.push_back(st);
                find(j+1, s, v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>v;
        find(0,s, v);
        return ans;
    }
};
