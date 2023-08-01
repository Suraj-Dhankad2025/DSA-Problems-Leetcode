// #define ll long long int;
typedef long long ll;
class MinStack {
public:
    stack<ll>st;
    ll mini;
    MinStack() {
        this->mini = INT_MIN;
    }
    
    void push(int val) {
        if(this->st.empty()){
            this->mini = val;
            this->st.push(val);
        }
        else{
            this->st.push(val-this->mini);
            if(val<this->mini){
                this->mini = val;
            }
        }
    }
    
    void pop() {
        if(!this->st.empty()){
            if(this->st.top()>=0){
                this->st.pop();
            }
            else{
                this->mini = (ll)(this->mini - this->st.top());
                this->st.pop();
            }
        }
    }
    
    int top() {
        if(this->st.size()==1){
            return this->st.top();
        }
        if(this->st.top()>=0){
            return (ll)(this->st.top()+this->mini);
        }
        else{
            return this->mini;
        }
    }
    
    int getMin() {
        return this->mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */