class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto it : nums) m[it]++;

        priority_queue<pair<int,int>> h; 
        for(auto &i:m) h.push({-i.second,i.first});
        
        vector<int> v;
        while(!h.empty())
        {
            for(int i = 0; i<-(h.top().first); i++)
            {
                v.push_back(h.top().second);
            }
            h.pop();
        }
        return v;
    }
};