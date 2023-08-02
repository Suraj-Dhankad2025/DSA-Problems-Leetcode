class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=-1;
        bool f=0;
        int tank = 0;
        int count = 0;
        int n = gas.size();
        int i=0;
        while(count<2*n){
            if(start==i){
                return i;
            }
            tank+=gas[i];
            if(tank>=cost[i]){
                if(start==-1){
                    start = i;
                }
                f=1;
                tank = tank - cost[i];
                i = (i+1)%n;
                count++;
            }
            else{
                start = -1;
                f=0;
                tank = 0;
                i = (i+1)%n;
                count++;
            }
        }
        return -1;
    }
};