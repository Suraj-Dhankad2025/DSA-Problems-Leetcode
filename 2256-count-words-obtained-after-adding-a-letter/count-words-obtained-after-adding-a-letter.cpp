class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> s;
        for(auto it:startWords){
            sort(it.begin(), it.end());
            s.insert(it);
        }
        int ans = 0;
        for(auto it:targetWords){
            string st = it;
            sort(st.begin(), st.end());
            for(int i = 0; i < st.size(); i++){
                string search = st.substr(0, i) + st.substr(i+1);                    
                if(s.find(search) != s.end()){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};