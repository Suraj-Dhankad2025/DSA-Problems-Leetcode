class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>>st;
        vector<int>v;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                st.push({s[i],i});
            }
            else if(s[i]==')'){
                bool f=0;
                if(!st.empty() && st.top().first=='('){
                    st.pop();
                    f=1;
                }
                if(f==0){
                    st.push({s[i], i});
                }
            }
        }
        while(!st.empty()){
            v.push_back(st.top().second);
            st.pop();
        }
        string t="";
        sort(v.begin(), v.end());
        int k=0;
        for(int i=0; i<s.size(); i++){
            if(k<v.size() && i==v[k]){
                k++;
                continue;
            }
            t+=s[i];
        }
        return t;
    }
};