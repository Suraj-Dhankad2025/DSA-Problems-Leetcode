class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0;
        stack<int>st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                st.push(ans);
                ans=0;
            }
            else{
                ans = st.top() + max(2*ans, 1);
                st.pop();
            }
        }
        return ans;
    }
};