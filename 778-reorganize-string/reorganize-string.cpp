class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>>pq;
        unordered_map<char, int>m;
        for(int i=0; i<s.length(); i++){
            m[s[i]]++;
        }
        for(auto i:m){
            pq.push({i.second, i.first});
        }
        string ans="";
        while(!pq.empty()){
            int f1 = pq.top().first;
            char c1 = pq.top().second;
            ans+=c1;
            pq.pop();
            if(pq.empty()){
                continue;
            }
            int f2 = pq.top().first;
            char c2 = pq.top().second;
            pq.pop();
            ans+=c2;
            f1--;
            f2--;
            if(f1>0){
                pq.push({f1,c1});
            }
            if(f2>0){
                pq.push({f2,c2});
            }
        }
        if(ans.size()<s.size())return "";
        return ans;
    }
};