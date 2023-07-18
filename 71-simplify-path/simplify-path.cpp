class Solution {
public:
    string simplifyPath(string path) {
        stack<string>s;
        stack<string>s1;
        for(int i=0; i<path.size(); i++){
            if(path[i]=='/')continue;
            string temp;
            while(i<path.size() && path[i]!='/'){
                temp+=path[i];
                i++;
            }
            if(temp==".") continue;
            else if(temp==".."){
                if(!s.empty())s.pop();
            }
            else{
                s.push(temp);
            }
        }
        while(!s.empty()){
            s1.push(s.top());
            s.pop();
        }
        path="";
        while(!s1.empty()){
            path+="/";
            path+=s1.top();
            s1.pop();
        }
        if(path.size()==0)return "/";
        return path;
    }
};