class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i=1; i<=9; i++){
            int j = i+1;
            int num=i;
            while(num<=high && j<=9){
                num = num*10 + j;
                if(num>=low && num<=high){
                    ans.push_back(num);
                }
                j++;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};