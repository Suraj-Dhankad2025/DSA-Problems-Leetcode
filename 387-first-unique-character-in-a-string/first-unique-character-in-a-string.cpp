class Solution {
public:
    int firstUniqChar(string s) {
        // int ans = -1;
        // queue<char>q;
        // q.push(s[0]);
        // for(int i=1; i<s.size(); i++){
        //     char c = q.front();
        //     q.pop();
        //     if(s[i]==c){
        //         continue;
        //     }
        //     else{
        //         ans = i;
        //         break;
        //     }
        //     q.push(s[i]);
        // }
        map<char, int>m;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }
        for(int i=0; i<s.size(); i++){
            if(m[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};