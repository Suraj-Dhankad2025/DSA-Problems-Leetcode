class Solution {
public:
    string getHint(string secret, string guess) {
        int x=0;
        int y=0;
        string ans="";
        int n = secret.size();
        unordered_map<char, int>m;
        for(int i=0; i<n; i++){
            if(secret[i]!=guess[i])
            m[secret[i]]++;
        }
        for(int i=0; i<n; i++){
            if(secret[i]==guess[i]){
                x++;
            }
            else if(m.find(guess[i])!=m.end() && m[guess[i]]>0){
                y++;
                m[guess[i]]--;

            }
        }
        ans+=to_string(x);
        ans+="A";
        ans+=to_string(y);
        ans+="B";
        return ans;
    }
};