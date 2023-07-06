class Solution {
public:
     vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<int> maxHeap;
        map<string, int> hashmap;
        vector<string> ans;
        for (auto &word:words) {
            hashmap[word]++;
        }
        for (auto &it:hashmap) maxHeap.push(it.second);
        while (k>0) {
            int topFreq = maxHeap.top();
            maxHeap.pop();
            for (auto &it:hashmap) {
                if (topFreq == it.second) {
                    ans.push_back(it.first);
                    hashmap.erase(it.first);
                    k--;
                    break;
                }
            }
        }
        return ans;
    }
};