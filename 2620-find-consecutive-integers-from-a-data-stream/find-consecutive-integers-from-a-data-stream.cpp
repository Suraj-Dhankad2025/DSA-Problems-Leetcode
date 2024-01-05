class DataStream {
public:
    int K;
    int val;
    int cnt;
    DataStream(int value, int k) {
        this->cnt = 0;
        this->val = value;
        this->K = k;
    }
    
    bool consec(int num) {
        if(val==num){
            cnt++;
        }
        else{
            cnt = 0;
        }
        if(cnt>=K){
            return true;
        }
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */