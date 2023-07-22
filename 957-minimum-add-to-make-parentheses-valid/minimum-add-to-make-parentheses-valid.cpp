class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                bool f=0;
                if(!st.empty() && st.top()=='(' ){
                    st.pop();
                    f=1;
                }
                if(f==0){
                    st.push(s[i]);
                }  
            }
        }
        return st.size();
    }
};