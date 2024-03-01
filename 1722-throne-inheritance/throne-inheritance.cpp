class ThroneInheritance {
    map<string, vector<string>>mp;
    map<string, int>dead;
    string king;
public:
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    void birth(string parentName, string childName) {
        mp[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead[name] = 1;
    }
    void find(string name, vector<string>&ans){
        if(dead[name]==0){
            ans.push_back(name);
        }
        for(auto i:mp[name]){
            find(i, ans);
        }
    }
    vector<string> getInheritanceOrder() {
        vector<string>ans;
        find(king, ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */