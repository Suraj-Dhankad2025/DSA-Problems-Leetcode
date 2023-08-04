class Solution {
public:
    vector<vector<string>>ans;
    bool isSafe(int row, int col, int n,vector<string>&board){
        int r=row;
        int c=col;
        while(r>=0){
            if(board[r][c]=='Q'){
                return false;
            }
            r--;
        }
        r=row;
        c=col;
        while(r>=0 && c<n){
            if(board[r][c]=='Q'){
                return false;
            }
            r--;
            c++;
        }
        r=row;
        c=col;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q'){
                return false;
            }
            r--;
            c--;
        }
        return true;
    }
    void find(int r, int c, int n, vector<string>&board){
        if(r==n){
            ans.push_back(board);
            return;
        }
        for(int c=0;c<n;c++){
            if(isSafe(r, c, n, board)){
                board[r][c] = 'Q';
                find(r+1, 0, n, board);
                board[r][c] ='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>a(n,"");
        string s(n,'.');
        for(int i=0;i<n;i++){
            a[i]=s;
        }
        find(0,0,n, a);
        return ans.size();
    }
};