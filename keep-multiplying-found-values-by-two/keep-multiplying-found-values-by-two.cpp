class Solution {
public:
    int findFinalValue(vector<int>& nums, int o) {
        map<int, int>m;
        int n = nums.size();
        int a = -1;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            if(o==nums[i]){
                a = nums[i];
            }
        }
        if(a==-1)return o;
        while(m.find(a)!=m.end()){
            a = a*2;
        }
        return a;
    }
};