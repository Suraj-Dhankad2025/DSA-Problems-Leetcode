class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    vector<std::vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<pair<int, int>> v;
        for(auto i : buildings){
            v.push_back({i[0], -i[2]});
            v.push_back({i[1], i[2]});
        }
        sort(v.begin(), v.end(), cmp);
        multiset<int> heights;
        heights.insert(0); 
        int curH = 0;
        for(int i = 0; i < v.size(); i++){
            int x = v[i].first;
            int h = v[i].second;
            if(h < 0){
                heights.insert(-h);
            } 
            else{
                heights.erase(heights.find(h));
            }
            if(curH != *heights.rbegin()){
                ans.push_back({x, *heights.rbegin()});
                curH = *heights.rbegin();
            }
        }
        return ans;
    }
};
