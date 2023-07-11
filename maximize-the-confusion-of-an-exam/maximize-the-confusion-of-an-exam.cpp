class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int count = 0;
        int ans = 0;
        int i = 0;
        int j= 0;
        while(j<a.size()){
            if(a[j] == 'F'){
                count++;
            }
            while(count>k){
                if(a[i]=='F'){
                    count--;
                }
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        count=0;
        j=0;
        i=0;
        while(j<a.size()){
            if(a[j] == 'T'){
                count++;
            }
            while(count>k){
                if(a[i]=='T'){
                    count--;
                }
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};