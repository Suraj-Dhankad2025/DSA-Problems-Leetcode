class Solution {
public:
    int maxWidthRamp(vector<int>& arr) {
       int ans=0;
       stack<int>s;
       for(int i=0; i<arr.size(); i++){
           if(s.empty() || arr[s.top()]>arr[i]){
                s.push(i);
           }
       }
       for(int i=arr.size()-1; i>=0; i--){
           while(!s.empty() && arr[s.top()]<=arr[i]){
                ans = max(ans, i-s.top());
                s.pop();
           }
       }
       return ans;
    }
};