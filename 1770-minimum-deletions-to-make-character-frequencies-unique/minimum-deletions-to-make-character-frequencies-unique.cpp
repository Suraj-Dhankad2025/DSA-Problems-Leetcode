class Solution {
public:
    int minDeletions(string s) {
        int ans=0;
        unordered_map<char, int>m;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }
        set<int>st;
        // for(auto i:m){
        //     st.insert(i.second);
        // }
        for(auto i:m){
            int f=i.second;
            while(st.find(f)!=st.end()){
                f--;
                ans++;
            }
            if(f>0){
                st.insert(f);
            }
        }
        return ans;
    }
};