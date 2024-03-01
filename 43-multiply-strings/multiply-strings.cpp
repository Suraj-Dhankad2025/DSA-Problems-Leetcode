class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        
        vector<int> sum(n + m, 0); 
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sumIdx = i + j;
                int carryIdx = i + j + 1;
                
                int total = mul + sum[carryIdx];
                sum[carryIdx] = total % 10;
                sum[sumIdx] += total / 10;
            }
        }

        string ans = "";
        for (int digit : sum) {
            if (!(ans.empty() && digit == 0)) 
                ans += to_string(digit);
        }
        
        return ans.empty() ? "0" : ans;
    }
};