class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0)return false;
        map<int, int>m;
        for(auto i:nums){
            m[i]++;
        }
        while(m.size()!=0){
            int s = m.begin()->first;
            for(int i=0; i<k; i++){
                if(m.find(s+i)!=m.end()){
                    m[s+i]--;
                    if(m[s+i]==0){
                        m.erase(s+i);
                    }
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};