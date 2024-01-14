class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>>q;
        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, -1, 0, 1};
        int ans=0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='X'){
                    q.push({i, j});
                    ans++;
                    while(!q.empty()){
                    int s = q.size();
                        while(s--){
                            auto [i,j] = q.front();
                            q.pop();
                            for(int k=0; k<4; k++){
                                int nr = i + dr[k];
                                int nc = j + dc[k];
                                if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='X'){
                                    board[nr][nc]='.';
                                    q.push({nr, nc});
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};