class Solution {
public:
    string smallestSubsequence(string s) {
        string ans="";
        vector<bool>v(26, false);
        vector<int>a(26,0);
        for(int i=0; i<s.size(); i++){
            a[s[i]-'a'] = i;
        }
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            if(v[s[i]-'a'])continue;
            while(st.size()>0 && st.top()>s[i] && i<a[st.top()-'a']){
                v[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            v[s[i]-'a'] = true;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};