class Solution {
public:
    vector<int> maxSubsequence(vector<int>& a, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        int n = a.size();
        unordered_map<int, int>m;
        for(int i=0; i<n; i++){
            pq.push(a[i]);
            if(pq.size()>k){
                m[pq.top()]++;
                pq.pop();
            }
        }
        vector<int>ans;
        for(auto i:a){
            if(m.find(i)!=m.end()){
                m[i]--;
                if(m[i]==0){
                    m.erase(i);
                }
            }
            else{
                ans.push_back(i);
            }
        }
        return ans;
    }
};