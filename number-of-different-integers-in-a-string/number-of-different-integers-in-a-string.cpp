class Solution {
public:
    int numDifferentIntegers(string word) {
        int n = word.size();
        int ans = 0;
        map<string , int >m;
        for(int i=0; i<n; i++){
            if(word[i]<='9' && word[i]>='0'){
                string s = "";
                while(word[i]<='9' && word[i]>='0'){
                    if(s.size()==0 && word[i]=='0'){
                        i++;
                        continue;
                    }
                    s+=word[i];
                    i++;
                }
                m[s]++;
            }
        }
        return m.size();
    }
};