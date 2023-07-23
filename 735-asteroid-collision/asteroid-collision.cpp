class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>s;
        vector<int>ans;
        
        for(int i=0; i<arr.size(); i++){
            bool f=0;
            while(!s.empty()&&s.top()>0&&arr[i]<0){                 
                if(abs(s.top())==abs(arr[i])){
                    s.pop();
                    f=1;
                    break;
                }
                else if(abs(s.top())>abs(arr[i])){
                    f=1;
                    break;
                }
                else{
                    s.pop();
                }
            }
            if(f==0){
                s.push(arr[i]);
            }  
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};