class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1; i<=n; i++){
            q.push(i);
        }
        while(q.size()>1){
            int c=0;
            while(c<k && q.size()>1){
                int f = q.front();
                q.pop();
                c++;
                if(c==k){
                    break;
                }
                q.push(f);
            }
        }
        return q.front();
    }
};