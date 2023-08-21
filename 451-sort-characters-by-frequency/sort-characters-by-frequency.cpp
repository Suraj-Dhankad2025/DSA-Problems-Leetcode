class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>>pq;
        unordered_map<char,int>m;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }
        for(auto it:m){
            pq.push({it.second, it.first});
        }
        string ans="";
        while(!pq.empty()){
            int f = pq.top().first;
            char c = pq.top().second;
            pq.pop();
            while(f--){
                ans+=c;
            }
        }
        return ans;
    }
};