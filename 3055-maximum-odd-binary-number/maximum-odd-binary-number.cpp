class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans="";
        int one=0,zero=0;
        for(auto i:s){
            if(i=='0'){
                zero++;
            }
            else{
                one++;
            }
        }
        while(one>1){
            ans+='1';
            one--;
        }
        while(zero){
            ans+='0';
            zero--;
        }
        ans+='1';
        return ans;
    }
};