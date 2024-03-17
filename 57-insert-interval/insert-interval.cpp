class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int s = newInterval[0];
        int e = newInterval[1];
        vector<vector<int>>ans;
        int i=0;
        while(i<intervals.size() && s>intervals[i][1]){    
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        while(i<intervals.size() && e>=intervals[i][0]){
            s = min(s, intervals[i][0]);
            e = max(e, intervals[i][1]);
            i++;
        }
        ans.push_back({s, e});
        while(i<intervals.size()){
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        return ans;
    }
};