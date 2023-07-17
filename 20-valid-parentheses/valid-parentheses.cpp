class Solution {
public:
    bool isValid(string s) {
         stack<char>st;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    if((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='[')){
                        st.pop();
                    }
                    else return 0;
                }
                else{
                    return 0;
                }
               
            }
        }
        if(st.empty())return 1;
        else return 0;
    }
       
    
};