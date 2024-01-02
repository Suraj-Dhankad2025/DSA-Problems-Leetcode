class Solution {
public:
    vector<string>ans;
    void find(int i,string s, string temp, map<int, vector<char>>&m){
        if(i==s.size()){
            ans.push_back(temp);
            return ;
        }
        for(auto it:m[(s[i])-'0']){
            temp.push_back(it);
            find(i+1,s,temp,m);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n==0)return {};
        map<int, vector<char>>m;
        char ch='a';
        int cnt=0;
        int i=2;
        while(i<=9){
            m[i].push_back(ch);
            ch++;
            cnt++;
            if(i!=7 && i!=9 && cnt==3){
                cnt = 0;
                i++;
            }
            if(i==7 || i==9){
                if(cnt==4){
                    cnt = 0;
                    i++;
                }
            }
        }
        find(0, digits, "", m);
        return ans;
    }
};