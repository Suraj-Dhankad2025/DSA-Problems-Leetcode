class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int count = 0;
        unordered_set<int>s;
        if(a.size()==0)return 0;
        int longest = INT_MIN;
        for(int i=0; i<a.size(); i++){
            s.insert(a[i]);
        }
        for(auto i:s){
            if(s.find(i-1)==s.end()){
                count=1;
                int x = i;
                while(s.find(x+1)!=s.end()){
                    x++;
                    count++;
                }
                longest = max(count, longest);
            }

        }
        return longest;
    }
};