class MyQueue {
public:
    stack<int>st1;
    stack<int>st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!this->st1.empty()){
            this->st2.push(this->st1.top());
            this->st1.pop();
        }
        this->st1.push(x);
        while(!this->st2.empty()){
            this->st1.push(this->st2.top());
            this->st2.pop();
        }
    }
    
    int pop() {
        int y = this->st1.top();
        this->st1.pop();
        return y;
    }
    
    int peek() {
        return this->st1.top();
    }
    
    bool empty() {
        return this->st1.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */