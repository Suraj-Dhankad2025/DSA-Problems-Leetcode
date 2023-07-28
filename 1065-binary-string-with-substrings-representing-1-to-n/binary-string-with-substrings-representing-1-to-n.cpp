class Solution {
public:
    bool queryString(string s, int n) {
       while(n) {
            string b = bitset<32>(n--).to_string();
            if(s.find(b.substr(b.find("1"))) == string::npos) return false;
        }
        return true;
    }
};