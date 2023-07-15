class Solution {
public: 
    vector<int> nextSmallerElement(vector<int>&a){
        vector<int>n;
        stack<int>s;
        for(int i=a.size()-1; i>=0; i--){
            if(s.size()>0 && a[s.top()]<a[i]){
                n.push_back(s.top());
            }
            else{
                while(!s.empty() && a[s.top()]>=a[i]){
                    s.pop();
                }
                if(!s.empty()){
                    n.push_back(s.top());
                }
                else{
                    n.push_back(-1);
                }
            }
            s.push(i);
        }
        reverse(n.begin(), n.end());
        return n;
    }
    vector<int> prevSmallerElement(vector<int>&a){
        vector<int>p;
        int n = a.size();
        stack<int>s;
        for(int i=0; i<n; i++){
            if(s.size()>0 && a[s.top()]<a[i]){
                p.push_back(s.top());
            }
            else{
                while(!s.empty() && a[s.top()]>=a[i]){
                    s.pop();
                }
                if(!s.empty()){
                    p.push_back(s.top());
                }
                else{
                    p.push_back(-1);
                }
            }
            s.push(i);
        }
        return p;
    }
    int find(vector<int>& h) {
        int ans=0;
        vector<int>prev, next;
        prev = prevSmallerElement(h);
        next = nextSmallerElement(h);
        for(int i=0; i<h.size(); i++){
             if(next[i]==-1){
                next[i]=h.size();
            }
            int area = (next[i]-prev[i]-1)*h[i];
            ans = max(ans, area);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
    int m = matrix[0].size();

    vector<int> arr(m, 0);
    int maxarea = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
            {
                arr[j] += 1;
            }
            else
            {
                arr[j] = 0;
            }
        }

        int area = find(arr);
        maxarea = max(area, maxarea);
    }
    return maxarea;
    }
};