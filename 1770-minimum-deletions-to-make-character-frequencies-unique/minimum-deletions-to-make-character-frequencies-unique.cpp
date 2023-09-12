class Solution {
public:
    int minDeletions(string s) {
        int ans=0;
        unordered_map<char, int>m;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }
        priority_queue<int>pq;
        for(auto i:m){
            pq.push(i.second);    
        }
        while(!pq.empty()){
            int f = pq.top();
            pq.pop();
            if(pq.empty()){
                continue;
            }
            int f1 = pq.top();
            pq.pop();
            if(f1==f){
                f1--;
                ans++;
                if(f1!=0)pq.push(f1);
                pq.push(f);
            }
            else{
                pq.push(f1);
            }
        }
        return ans;
    }
};