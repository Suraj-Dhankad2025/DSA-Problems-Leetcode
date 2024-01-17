class Solution {
public:
    void findlps(string s, vector<int>&lps) {
	    int pre = 0;
	    int suf = 1;
	    lps[0] = 0;
	    while(suf<s.size()){
	        if(s[pre]==s[suf]){
	            lps[suf] = pre + 1;
	            pre++;
	            suf++;
	        }
	        else{
	            if(pre==0){
	                lps[suf] = 0;
	                suf++;
	            }
	            else{
	                pre = lps[pre - 1];
	            }
	        }
	    }
	}
    vector<int> KMP(string pat,string txt){
        int N = txt.length();
        int M = pat.length();
        vector<int> lps(M,0);
        vector<int> result;
        findlps(pat,lps);
        int i = 0;
        int j = 0;
        while(i<N){
            if(pat[j] == txt[i]){
                i++;
                j++;
            }
            if(j == M){
                result.push_back(i-j);
                j = lps[j-1];
            }
            else if(i < N && pat[j] != txt[i]){
                if(j != 0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return result;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length();
        vector<int> v1 = KMP(a,s);
        vector<int> v2 = KMP(b,s);
        vector<int> ans;
         for(auto &i: v1){
            int x = lower_bound(v2.begin(),v2.end(),i-k)-v2.begin();
            if(x==v2.size())break;
            if(abs(v2[x]-i)<=k){
                ans.push_back(i);
            }
        }
        return ans;
    }
};