class Solution {
private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j, int prevHeight, bool isPacific, bool isAtlantic) {
        if (i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size())
            return;
        
        if (visited[i][j] || heights[i][j] < prevHeight)
            return;

        visited[i][j] = true;
        
        if (isPacific && isAtlantic)
            return;

        dfs(heights, visited, i - 1, j, heights[i][j], isPacific, isAtlantic);
        dfs(heights, visited, i + 1, j, heights[i][j], isPacific, isAtlantic);
        dfs(heights, visited, i, j - 1, heights[i][j], isPacific, isAtlantic);
        dfs(heights, visited, i, j + 1, heights[i][j], isPacific, isAtlantic);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty())
            return {};
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0, INT_MIN, true, false);
            dfs(heights, atlantic, i, n - 1, INT_MIN, false, true);
        }
        
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j, INT_MIN, true, false);
            dfs(heights, atlantic, m - 1, j, INT_MIN, false, true);
        }
        
        vector<vector<int>> result;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }
        
        return result;
    }
};