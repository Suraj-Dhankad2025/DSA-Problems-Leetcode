class Solution {
public:
    void find(int i, string digits, vector<string>&ans,vector<string>&m, string &a){
        if(i==digits.size()){
            ans.push_back(a);
            return ;
        }
        string str = m[(digits[i]-'0')-2];
        for(auto it:str){
            a+=it;
            find(i+1, digits, ans, m,a);
            a.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        int n = digits.size();
        if(n==0){
            return ans;
        }
        string a="";
        vector<string>m(8);
        m[0] = "abc";
        m[1] = "def";
        m[2] = "ghi";
        m[3] = "jkl";
        m[4] = "mno";
        m[5] = "pqrs";
        m[6] = "tuv";
        m[7] = "wxyz";
        find(0,digits, ans,m,a);
        return ans;
    }
};