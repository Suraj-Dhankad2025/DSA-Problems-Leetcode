class Solution {
public:
    vector<int> kthSmallestMerge(vector<int> a, vector<int> b, int k = 200) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        int n = a.size(), m = b.size();
        for(int i = 0; i < min(n, k); ++i) {
            pq.push({a[i] + b[0], i, 0});
        }
        vector<int> res;
        while(k > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            res.push_back(sum);
            pq.pop();
            if(j + 1 < m) pq.push({a[i] + b[j + 1], i, j + 1});
            k--;
        }

        return res;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        if(mat.size()==1){
            return mat[0][k-1];
        }
        vector<int>res = mat[0];
        for(int row = 1; row < mat.size(); ++row) {
            res = kthSmallestMerge(mat[row], res, k);
        }
        return res[k - 1];
    }
};