class Solution {
public:
    bool check(vector<int>a, int k){
        for(auto i:a){
            if(i<k)return true;
        }
        return false;
    }
    int takeCharacters(string s, int k){
        int n=s.size();
        vector<int>a(3,0);
        for(auto i:s){
            a[i-'a']++;
        }
        if(check(a,k)){
            return -1;
        }
        int i=0;
        int j=0;
        int ans=0;
        while(i<n){
            a[s[i]-'a']--;
            while(check(a,k)){
                a[s[j]-'a']++;
                j++;
            }
            ans = max(i-j+1,ans);
            i++;
        }
        return s.length()-ans;
    }
};