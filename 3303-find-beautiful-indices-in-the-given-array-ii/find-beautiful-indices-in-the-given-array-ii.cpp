class Solution {
    vector<int> computePrefixFunction(const string& pattern) {
    int m = pattern.length();
    vector<int> prefix(m, 0);
    int k = 0;
    for (int q = 1; q < m; ++q) {
        while (k > 0 && pattern[k] != pattern[q]) {
            k = prefix[k - 1];
        }
        if (pattern[k] == pattern[q]) {
            k++;
        }
        prefix[q] = k;
    }
    return prefix;
}
vector<int> rollingHashSearch(const string& parent, const string& pattern) {
    vector<int> occurrences;
    int n = parent.length();
    int m = pattern.length();
    if (m == 0) {
        for (int i = 0; i < n; ++i) {
            occurrences.push_back(i);
        }
        return occurrences;
    }
    vector<int> prefix = computePrefixFunction(pattern);
    int q = 0;
    for (int i = 0; i < n; ++i) {
        while (q > 0 && pattern[q] != parent[i]) {
            q = prefix[q - 1];
        }
        if (pattern[q] == parent[i]) {
            q++;
        }
        if (q == m) {
            occurrences.push_back(i - m + 1);
            q = prefix[q - 1];
        }
    }
    return occurrences;
}


public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> as = rollingHashSearch(s, a);
        vector<int> bs = rollingHashSearch(s, b);
        vector<int> ans;
        for (int i = 0; i < as.size(); i++) {
            auto op1 = lower_bound(bs.begin(), bs.end(), as[i] - k);
            auto op2 = lower_bound(bs.begin(), bs.end(), as[i]);
            if ((op1 != bs.end() && *op1 >= as[i] - k && *op1 <= as[i]) || (op2 != bs.end() && *op2 <= as[i] + k && *op2 >= as[i])) {
                ans.push_back(as[i]);
            }
        }
        return ans;
    }
};