class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n=preorder.length();
        int node=1;
        string str;
        stringstream ss(preorder);
        while(getline(ss,str,',')){
            node--;
            if(node<0)return false;
            if(str!="#")node+=2; 
        }
        return node==0;
    }
};