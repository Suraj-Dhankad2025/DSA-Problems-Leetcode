class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int answer = 0;
        int dp[26][26];
        bool middle = false;
        for (auto word: words) {
            dp[word[0] - 'a'][word[1] - 'a'] += 1;
        }

        for (int i=0; i<26; i++) {
            for (int j=i+1; j<26; j++) {
                answer += 4 * min(dp[i][j], dp[j][i]);
            }
            if (dp[i][i] % 2 == 1) {
                middle = true;
                answer += 2 * (dp[i][i] - 1);
            } else {
                answer += 2 * dp[i][i];
            }
        }

        if (middle) answer += 2;
        return answer;
    }
};