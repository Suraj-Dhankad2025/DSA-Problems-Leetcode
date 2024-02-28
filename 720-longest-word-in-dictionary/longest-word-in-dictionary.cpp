struct Node{
    Node* links[26];
    bool end=false;
};
class Trie{
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(string &word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->links[word[i]-'a']==NULL){
                node->links[word[i]-'a'] = new Node();
            }
            node = node->links[word[i]-'a'];
        }
        node->end = true;
    }
    bool check(string &word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            node = node->links[word[i]-'a'];
            if(node->end==false)return false;
        }
        return true;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie t;
        for(auto i:words){
            t.insert(i);
        }
        string ans = "";
        for(auto i:words){
            if(t.check(i)){
                if(ans.size()<i.size() || (ans.size()==i.size() && i<ans)){
                    ans = i;
                }
            }
        }
        return ans;
    }
};