class Solution {
public:
    int minimumDeletions(string s) {
        stack<int>st;
        int del=0;
        for(int i=0; i<s.size(); i++){
            if(!st.empty() && st.top()=='b' && s[i]=='a'){
                del++;
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return del;
    }
};