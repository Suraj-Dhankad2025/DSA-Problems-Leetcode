class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>s;
        for(int i=0; i<num.size(); i++){
            while(k>0 && !s.empty() && s.top()>num[i]-'0'){
                s.pop();
                k--;
            } 
            if(s.empty()&&num[i]=='0'){
                continue;
            }
            else{
                s.push(num[i]-'0');
            }
        }
        while(!s.empty()&&k>0){
            s.pop();
            k--;
        }
        string ans="";
        while(!s.empty()){
            ans+=to_string(s.top());
            s.pop();
        }
        if(ans.length()==0){
            ans+='0';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};