class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int>st;
        st.push(-1);
        int maxi = 0;
        // int ans=0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(i);
            }
            else {
                if(!st.empty()){
                    st.pop();
                }
                if(!st.empty()){
                    maxi=max(maxi,i-st.top());
                }
                else{
                    st.push(i);
                }
            }
        }
        return maxi;
    }
};