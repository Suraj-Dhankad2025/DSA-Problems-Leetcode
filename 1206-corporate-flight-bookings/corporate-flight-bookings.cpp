class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n,0);
        for(int i=0; i<bookings.size(); i++){
            int s = bookings[i][0];
            int e = bookings[i][1];
            int seats = bookings[i][2];
            ans[s-1] = ans[s-1] + seats;
            if(e<n)ans[e] = ans[e] - seats;
        }
        int pre=ans[0];

        for(int i=1; i<n; i++){
            pre+=ans[i];
            ans[i] = pre;
        }
        return ans;
    }
};