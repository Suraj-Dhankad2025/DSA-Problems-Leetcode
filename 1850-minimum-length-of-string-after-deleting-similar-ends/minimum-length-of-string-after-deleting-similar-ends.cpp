class Solution {
public:
    int minimumLength(string s) {
        if (s.empty()) return 0; 
        int l = 0;
        int r = s.size() - 1;
        int ans = s.size();

        while (l < r && s[r] == s[l]) {
            char ch1 = s[l];
            while (l <= r && ch1 == s[l]) {
                l++;
                ans--;
            }
            while (l <= r && ch1 == s[r]) {
                r--;
                ans--;
            }
        }
        return ans;
    }
};