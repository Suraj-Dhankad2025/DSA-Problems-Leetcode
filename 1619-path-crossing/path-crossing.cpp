class Solution {
public:
    bool isPathCrossing(string path) {
        vector<pair<int, int>>v;
        set<pair<int, int>>s;
        int x=0;
        int y=0;
        v.push_back({x,y});
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
            v.push_back({x,y});
        }
        for(auto i:v){
            s.insert(i);
        }
        if(s.size()==v.size())return false;
        return true;
    }
};