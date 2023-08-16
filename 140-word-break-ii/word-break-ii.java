class Solution {
    List<String> res = new ArrayList<String>();
    HashSet<String> set;
    public List<String> wordBreak(String s, List<String> wordDict) {
       set = new HashSet<String>(wordDict);
       fun(s,0,"");
       return res;
    }
    void fun(String s, int idx,String temp){

        if(idx == s.length()){
            // if(res.size() != 0)return;
            String t = temp.substring(0,temp.length()-1);
            res.add(t);
            return;
        }

        for(int i = idx; i<s.length(); i++){
            if(!set.contains(s.substring(idx,i+1)))continue;
            // ÷z.add(s.substring(idx,i+1));
            fun(s,i+1,temp+s.substring(idx,i+1)+" ");
            // temp.remove(temp.size()-1);
        }
    }
}