class MyQueue {
public:
    stack<int> s1, s2;
    int front;
   
    void push(int x) {
        if (s1.empty()) front = x;
        s1.push(x);
    }
    
    int pop() { 
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int to_pop = s2.top();
        s2.pop();
        while (!s2.empty()) {
            if (s1.empty()) front = s2.top();
            s1.push(s2.top());
            s2.pop();
        }
        return to_pop;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        return (s1.empty());
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