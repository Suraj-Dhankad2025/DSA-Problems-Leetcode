class Solution {
public:
    string smallestSubsequence(string s) {
    //     string ans="";
    //     vector<bool>v(26, false);
    //     vector<int>a;
    //     for(int i=0; i<s.size(); i++){
    //         a[s[i]-'a'] = i;
    //     }
    //     stack<char>st;
    //     for(int i=0; i<s.size(); i++){
    //         if(v[s[i]-'a'])continue;
    //         while(st.size()>0 && st.top()>s[i] && i<a[st.top()-'a']){
    //             v[st.top()-'a'] = false;
    //             st.pop();
    //         }
    //         st.push(s[i]);
    //         v[s[i]-'a'] = true;
    //     }
    //     while(!st.empty()){
    //         ans+=st.top();
    //         st.pop();
    //     }
    //     reverse(ans.begin(), ans.end());
    //     return ans;
    // }
    vector<int> lastIndex(26, 0);
        for (int i = 0; i < s.length(); i++){
            lastIndex[s[i] - 'a'] = i; 
        }
        vector<bool> seen(26, false);
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';
            if (seen[curr]) continue;
            while(st.size()>0&&st.top()>s[i]&&i<lastIndex[st.top()-'a']){
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]); 
            seen[curr] = true; 
        }
        string ans = "";
        while (st.size() > 0){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};