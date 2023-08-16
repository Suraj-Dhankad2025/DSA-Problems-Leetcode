class Solution {
public:
    vector<string>ans;
    set<string>st;
    void make(int ind,string &s, string temp){
        if(ind>=s.size()){
            string t = temp.substr(0,temp.length()-1);
            ans.push_back(t);
            return ;
        }
        for(int i=ind; i<s.length(); i++){
            if(!st.count(s.substr(ind,i+1-ind))){
                continue;
            } 
            make(i+1, s, temp+(s.substr(ind, i+1-ind))+" ");
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto i:wordDict){
            st.insert(i);
        }
        make(0, s, "");
        return ans;
    }
};