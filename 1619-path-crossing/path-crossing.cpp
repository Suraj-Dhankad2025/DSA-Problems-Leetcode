class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>,int>mp;
        int x=0;
        int y=0;
        mp[{x,y}]++;
        for(int i=0;i<path.length();i++){
            if(path[i]=='N'){
                y++;
            }
            else if(path[i]=='S'){
                y--;
            }
            else if(path[i]=='E'){
                x++;
            }
            else{
                x--;
            }
            mp[{x,y}]++;
        }
        for(auto it:mp){
            if(it.second>=2){
                return true;
            }
        }
        return false;
    }
};