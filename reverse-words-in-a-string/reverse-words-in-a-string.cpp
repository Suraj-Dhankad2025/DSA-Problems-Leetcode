class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string ans = "";
        int i=0;
        while(i<s.size()){
            if(s[i]==' '){
                i++;
                continue;
            } 
            string t="";
            while(s[i]!=' ' && i<s.size()){
                t+=s[i];
                i++;
            }
            st.push(t);
            i++;
        }
        while(!st.empty()){
            string str = st.top();
            st.pop();
            ans+=str;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};