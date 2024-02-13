class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto s:words){
            int i=0,j=s.size()-1;
            while(i<j){
                if(s[i]!=s[j])break;
                i++;
                j--;
            }
            if(i>=j)return s;
        }
        return "";
    }
};