class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        set<string>t;
        int j=0;
        map<string, int>m;
        string st="";
        while(j<s.size()){
            if(j<9){
                st+=s[j];
                j++;
            }
            else{
                st+=s[j];
                m[st]++;
                if(m[st]>1){
                    t.insert(st);
                }
                st.erase(st.begin(), st.begin()+1);
                j++;
            }
        }
        for(auto i:t){
            ans.push_back(i);
        }
        return ans;
    }
};