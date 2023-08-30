class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>>pq;
        
        for(auto i:nums){
            int l = i.length();
            pq.push({l,i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top().second;
    }
};