class Solution {
public:
    string decodeAtIndex(string t, int k) {
        stack<pair<char, int>>s;
        long long int len=0;
        char ans;
        for(int i=0; i<t.size(); i++){
            cout<<len<<" ";
            if(len==k ){
                string a="";
                a+=s.top().first;
                cout<<"hi";
                return a;
            }
            if(len>k){
                break;
            }
            if(t[i]>='a' && t[i]<='z'){
                len++;
                s.push({t[i], len});
            }
            else if(t[i]-'0'<=9 && t[i]-'0'>0){
                len = len*(t[i]-'0');
            }
        }
        while(!s.empty()){
            char c = s.top().first;
            int l = s.top().second;
            s.pop();
            if(k<l){
                continue;
            }
            else if(k%l==0){
                ans =  c;
                break;
            }
            else{
                k = k%l;
            }
        }
        string a="";
        a+=ans;
        return a;
    }
};