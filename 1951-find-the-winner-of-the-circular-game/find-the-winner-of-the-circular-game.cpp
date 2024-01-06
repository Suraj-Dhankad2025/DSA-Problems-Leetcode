class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1; i<=n; i++){
            q.push(i);
        }
        while(q.size()>1){
            int c=0;
            while(c<k-1){
                int friends = q.front();
                q.pop();
                q.push(friends);
                c++;
            }
            q.pop();
        }
        return q.front();
    }
};