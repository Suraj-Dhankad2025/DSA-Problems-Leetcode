class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        // vector<int>ans;
        // int len = nums[0].size();
        // int ind=len-1;
        // for(int i=0; i<q.size(); i++){
        //     int k = q[i][0];
        //     priority_queue<pair<string, int>>pq;
        //     for(int j=0; j<nums.size(); j++){
        //         int x = q[i][1];
        //         ind = len-x;
        //         int c=0;
        //         string s = nums[j];
        //         string temp="";
        //         while(c<x){
        //             temp+=s[ind];
        //             ind++;
        //             c++;
        //         }
        //         pq.push({temp, j});
        //         if(pq.size()>k){
        //             pq.pop();
        //         }
        //     }
        //     ans.push_back(pq.top().second);
        // }
        // return ans;
       vector<int> res;
        for(auto x:q)
        {
            priority_queue<pair<string,int>> v;
            for(int i=0;i<nums.size();i++)
            {
                int t=nums[i].length()-x[1];
                string p=nums[i].substr(t,x[1]);
                if(v.size()<x[0])
                    v.push({p,i});
                else
                {
                    if(v.top().first > p)
                    {
                        v.pop();
                        v.push({p,i});
                    }
                }
            }
            int val=v.top().second;
            res.push_back(val);
        }
        return res;
    }
};