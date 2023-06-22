class Solution {
public:
    string minWindow(string s, string t) {
    map<char,int>mp;
        int cnt=0;
        for(int i=0;i<t.length();i++){
            if(mp.find(t[i])==mp.end()){
                cnt++;
            }
            mp[t[i]]++;
        }
        int i=0;
        int j=0;
        int f=0;
        int minlen=INT_MAX;
        int e=0;
        while(j<s.length()){
            mp[s[j]]--;
            if(mp[s[j]]==0){
                cnt--;
            }
            j++;
            if(cnt==0){
                while(cnt==0&&i<j){
                    mp[s[i]]++;
                    if(mp[s[i]]==1){
                        cnt++;
                    }
                    i++;
                }
                if(j-i+1<minlen){
                    f=i-1;
                    e=j-1;
                    minlen=j-i+1;
                }
            }
        }
        if(minlen==INT_MAX)
           return "";
        string ans="";
        for(int i=f;i<=e;i++){
            ans.push_back(s[i]);
        }
        return ans;
        // unordered_map<char , int>m;
        // if(t.size()>s.size())return "";
        // if(s==t) return s;
        // int count = 0;
        // int st = -1,e = -1;
        // int ans = INT_MAX;
        // for(auto i:t){
        //     if(m[i]==0){
        //         count++;
        //     }
        //     m[i]++;
        // }
        // int i=0; 
        // int j=0;
        // int n = s.size();
        // while(j<n){
        //     if(m.find(s[j])!=m.end()){
        //         m[s[j]]--;
        //         if(m[s[j]]==0){
        //             count--;
        //         }
        //     }
        //     if(count==0){ 
        //         if(j-i+1<ans){
        //             ans = j-i+1;
        //             st=i;
        //             e=j;
        //         }   
        //         while(count==0){
        //             if(m.find(s[i])!=m.end()){
        //                 m[s[i]]++;  
        //                 if(m[s[i]]>0){
        //                     count++;
        //                 }  
        //             } 
        //             i++;    
        //             if(j-i+1<ans && count==0){
        //                 st=i;
        //                 e=j;
        //                 ans=j-i+1;
        //             }
        //         } 
        //     }
        //     j++;
        // }
        // string a="";
        // if(st==-1 && e==-1)return a;
        // for(int k=st; k<=e; k++){
        //     a+=s[k];
        // }
        // return a;
    }
};