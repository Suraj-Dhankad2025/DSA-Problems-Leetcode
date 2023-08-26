class Solution {
public:
    vector<int> find(vector<int> nums1, vector<int> nums2, int k) {
        vector<int>ans;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;
        
        for(int i=0; i<nums1.size(); i++){
            pq.push({nums1[i]+nums2[0], i, 0});
        }
        while(!pq.empty() && k>0){
            auto [sum, i,j] = pq.top();
            pq.pop();
            ans.push_back(sum);
            if(j+1<nums2.size()){
                pq.push({nums1[i]+nums2[j+1], i, j+1});
            }
            k--;
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        if(mat.size()==1){
            return mat[0][k-1];
        }
        vector<int>ans = mat[0];
        for(int i=1; i<mat.size(); i++){
            ans = find(mat[i],ans,k);
        }
        return ans[k-1];
    }
};